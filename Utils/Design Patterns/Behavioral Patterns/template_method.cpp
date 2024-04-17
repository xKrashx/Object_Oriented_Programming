#include <iostream>
#include <new>

class Abstract{
public:
	void TemplateMethod(){
		FunctionA();
		FunctionB();
		FunctionC();
	}

  	virtual ~Abstract() = default;

private:
	virtual void FunctionA() = 0;
	virtual void FunctionB() = 0;
	virtual void FunctionC() = 0;
};

class A : public Abstract{
private:
	void FunctionA() override{ std::cout << 1; }
	void FunctionB() override{ std::cout << 2; }
	void FunctionC() override{ std::cout << 3; }
};

class B : public Abstract {
private:
	void FunctionA() override{ std::cout << 4; }
	void FunctionB() override{ std::cout << 5; }
	void FunctionC() override{ std::cout << 6; }
};

int main() {
	Abstract *a = new(std::nothrow) A;
	Abstract *b = new(std::nothrow) B;

	if(!a || !b){

		delete a;
		delete b;

		return 0;

	}

	a -> TemplateMethod();  // 123
	b -> TemplateMethod();  // 456

	delete a;
	delete b;

	return 0;
}
