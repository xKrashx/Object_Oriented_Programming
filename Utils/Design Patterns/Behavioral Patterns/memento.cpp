#include <stdexcept>
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

class Memento{
public:
	Memento(int32_t n = 0): m_Value(n){}

	int32_t Value() const{ return m_Value; }

private:
  	int32_t m_Value;
};

class Originator {
public:
	Originator(int32_t n = 0): m_Value(n){}

	Memento ValueMemento() const{ return Memento{m_Value}; }

	void Load(Memento const &memento){ m_Value = memento.Value(); }

	void PrintValue() const{ std::cout << m_Value << '\n'; }

	void SetValue(int32_t n){ m_Value = n; }

private:
  	int32_t m_Value;
};

class Caretaker {
public:
	Memento &State(std::string const &str){
		for(Pair &pair : m_Mementos)
			if(pair.key == str)
				return pair.value;
		throw std::invalid_argument("Couldn't find element with the given key");
	}

	void SetState(std::string const &str, Memento const &memento){ m_Mementos.push_back({str, memento}); }

private:
	struct Pair{
		std::string key;
		Memento value;
	};

private:
  	std::vector<Pair> m_Mementos;
};

int main(){
	Caretaker caretaker;
	Originator originator(1);

	caretaker.SetState("one", originator.ValueMemento());
	originator.SetValue(2);
	caretaker.SetState("two", originator.ValueMemento());
	originator.SetValue(3);
	caretaker.SetState("three", originator.ValueMemento());

	originator.Load(caretaker.State("two"));
	originator.PrintValue();  // 2
	originator.Load(caretaker.State("one"));
	originator.PrintValue();  // 1
	originator.Load(caretaker.State("three"));
	originator.PrintValue();  // 3

	return 0;
}
