#include <iostream>
#include <new>

class Prototype{
public:
    virtual Prototype *Clone() = 0;
    virtual ~Prototype() = default;
};

class A : public Prototype{
public:
	Prototype *Clone() override {
		return new(std::nothrow) A(*this);
	}
};

int main() {
	Prototype *p = new A;
	Prototype *q = p -> Clone();

	if(!q){

		delete p;
		return 0;

	}
	if(p != q) std::cout << "p should be different from q\n";

	delete p;
	delete q;

	return 0;
}
