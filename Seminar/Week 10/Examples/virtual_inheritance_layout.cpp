#include <iostream>

class I {
public:
	int i;
public:
	virtual void foo() {
		std::cout << "I::foo" << std::endl;
	}
	virtual void bar() {
		std::cout << "I::bar" << std::endl;
	}
};

class C : virtual public I {
public:
	int c1;
	int c2;

public:
	virtual void foo() {
		std::cout << "C::foo" << std::endl;
	}
};

class B : virtual public I {
public:
	int b1;
	int b2;

public:
	virtual void baz() {
		std::cout << "B::baz" << std::endl;
	}
};

class A : public B, public C {
public:
	int a1;
	int a2;

public:
	virtual void seta1(int a) {
		a1 = a;
	}
	virtual void seta2(int a) {
		a2 = a;
	}
};

int main() {

	A *a = new A();
	B *b = a;
	C *c = a;
    I *i = a;

	int A::*ptm = &A::a1;
	int A::*ptm1 = &A::a2;
	int B::*ptm2 = &B::b1;
	int B::*ptm3 = &B::b2;
	int C::*ptm4 = &C::c1;
	int C::*ptm5 = &C::c2;
	int I::*ptm6 = &I::i;

	std::cout << "a: " << a << '\n';
	std::cout << "Offsets:\n";
	std::cout << "--------\n";
	std::cout << "A - *v-table: " << (char *)a - (char *)a << '\n';
	std::cout << "A - Fields:\na1: " << (char *)&(a->*ptm) - (char *)a << "\na2: " << (char *)&(a->*ptm1) - (char *)a << '\n';
	std::cout << "--------\n";
	std::cout << "B - *v-table: " << (char *)b - (char *)a << '\n';
	std::cout << "B - Fields:\nb1: " << (char *)&(a->*ptm2) - (char *)a << "\nb2: " << (char *)&(a->*ptm3) - (char *)a << '\n';
	std::cout << "--------\n";
	std::cout << "C - *v-table: " << (char *)c - (char *)a << '\n';
	std::cout << "C - Fields:\nc1: " << (char *)&(a->*ptm4) - (char *)a << "\nc2: " << (char *)&(a->*ptm5) - (char *)a << '\n';
	std::cout << "--------\n";
	std::cout << "I - *v-table: " << (char *)i - (char *)a << '\n';
	std::cout << "I - Fields:\nc1: " << (char *)&(a->*ptm6) - (char *)a << '\n';

	return 0;
}