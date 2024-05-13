#include <iostream>
#include <cstdint>
#include <vector>

class Subject;

class Observer{
public:
	explicit Observer(Subject &subject): m_Subject(subject){}
	virtual void Update() = 0;
	virtual ~Observer() = default;

protected:
  	Subject &m_Subject;
};

class Subject{
public:
	void Append(Observer *observer){ m_Observers.emplace_back(observer); }

	void Remove(Observer *observer){
		for(std::vector<Observer *>::iterator iter = m_Observers.begin(); iter != m_Observers.end(); ++iter)
			if(*iter == observer)
				m_Observers.erase(iter);
	}

	void Notify(){
		for (Observer * const &observer : m_Observers) {
			observer -> Update();
		}
	}

	void SetValue(int32_t n){ m_Value = n; }

	int32_t Value() const{ return m_Value; }

private:
	std::vector<Observer *> m_Observers;
	int32_t m_Value = 0;
};

class ObserverA : public Observer{
public:
	using Observer::Observer;

	void Update() override{
		std::cout << "Subject value in A: " << m_Subject.Value() << '\n';
	}
};

class ObserverB : public Observer{
public:
	using Observer::Observer;

	void Update() override{
		std::cout << "Subject value in B: " << m_Subject.Value() << '\n';
	}
};

int main(){
	Subject subject;
	ObserverA a(subject);
	ObserverB b(subject);

	subject.Append(&a);
	subject.Append(&b);

	subject.SetValue(3);
	subject.Notify();  // subject_ value in A: 3\nsubject value in B: 3\n

	return 0;
}
