#include <cassert>

template <typename T>
class Singleton{
public:
	static T &Instance();

	Singleton(Singleton const &) = delete;
	Singleton &operator =(const Singleton&) = delete;

private:
	Singleton() = default;
	~Singleton() = default;
};

template <typename T>
T &Singleton<T>::Instance(){
	static T instance;
	return instance;
}

class A{};

int main(){
	A &a = Singleton<A>::Instance();
	A &b = Singleton<A>::Instance();
	assert(&a == &b);
	return 0;
}
