#include <iostream>
#include <vector>
#include <utility>

class Flyweight{
public:
	virtual void Print() = 0;
	virtual ~Flyweight() = default;
};

class ConcreteFlyweight : public Flyweight{
public:
	explicit ConcreteFlyweight(char key) : m_Key(key) {}

	void Print() override { std::cout << m_Key << '\n'; }

private:
  	char m_Key;
};

class FlyweightFactory{
public:
	Flyweight *FlyweightPtr(char c) {
		for(Pair const &pair : m_Map)
			if(pair.m_key == c){
				std::cout << "existing key: ";
				return pair.ptr;
			}

		Flyweight *ptr = new ConcreteFlyweight(c);
		m_Map.push_back({ c, std::move(ptr) });
		return m_Map.back().ptr;
	}

private:
	struct Pair{
		char m_key;
		Flyweight *ptr;
	};

private:
  	std::vector<Pair> m_Map;
};


int main() {
	FlyweightFactory factory;
	factory.FlyweightPtr('a') -> Print();  // a
	factory.FlyweightPtr('a') -> Print();  // existing key: a
	factory.FlyweightPtr('b') -> Print();  // b
	factory.FlyweightPtr('b') -> Print();  // existing key: a
	return 0;
}
