#include <iostream>

class Strategy{
public:
	virtual void Print() = 0;
	virtual ~Strategy() = default;
};

class StrategyA : public Strategy{
public:
  	void Print() override{ std::cout << "StrategyA\n"; }
};

class StrategyB : public Strategy{
public:
  	void Print() override{ std::cout << "StrategyB\n"; }
};

class Context{
public:
	Context(Strategy *strategy): m_Strategy(std::move(strategy)){}
	~Context(){ delete m_Strategy; }

	void Print() const { m_Strategy -> Print(); }

private:
  	Strategy *m_Strategy;
};

int main(){
	Context a{new StrategyA};
	Context b{new StrategyB};

	a.Print();  // StrategyA
	b.Print();  // StrategyB

	return 0;
}
