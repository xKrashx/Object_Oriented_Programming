#include <iostream>
#include <vector>
#include <string>

class Colleague;

class Mediator {
public:
	virtual void Notify(Colleague *, std::string const &) = 0;
	virtual ~Mediator() = default;
};

class Colleague {
public:
	explicit Colleague(Mediator *mediator) : m_Mediator(mediator){}
	virtual ~Colleague() = default;

	virtual void Send(std::string const &) = 0;
	virtual void Receive(std::string const &) const = 0;

protected:
  	Mediator *m_Mediator;
};

class ColleagueA : public Colleague{
public:
	using Colleague::Colleague;

	void Send(std::string const &str) override{
		m_Mediator -> Notify(this, str);
	}

	void Receive(std::string const &str) const override{
		std::cout << "A receive: " << str << '\n';
	}
};

class ColleagueB : public Colleague{
public:
	using Colleague::Colleague;

	void Send(std::string const &str) override{
		m_Mediator -> Notify(this, str);
	}

	void Receive(std::string const &str) const override{
		std::cout << "B receive: " << str << '\n';
	}
};

class ConcreteMediator : public Mediator{
public:
	void Append(Colleague *colleague){
		m_Colleagues.emplace_back(colleague);
	}

	void Notify(Colleague *searchColleague, std::string const &str) override{
		for(Colleague * const &colleague : m_Colleagues)
			if(colleague != searchColleague)
				colleague -> Receive(str);
	}

private:
  	std::vector<Colleague *> m_Colleagues;
};

int main() {
	ConcreteMediator mediator;
	ColleagueA colleagueA(&mediator);
	ColleagueB colleagueB(&mediator);

	mediator.Append(&colleagueA);
	mediator.Append(&colleagueB);

	colleagueA.Send("hello");  // B receive: hello
	colleagueB.Send("world");  // A receive: world

	return 0;
}
