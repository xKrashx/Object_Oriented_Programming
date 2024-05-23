/*
    Write a comment to explain the output
*/

#include <iostream>

class A
{
public:
    void baz()              { std::cout << "Calling A::baz() " << std::endl; }
    virtual void bar()      { std::cout << "Calling A::bar() " << std::endl; }
};

class B : public A
{
public:
    void baz()              { std::cout << "Calling B::baz() " << std::endl; }
    virtual void bar()      { std::cout << "Calling B::bar() " << std::endl; }
};

void funcCaller(A* someA)
{
	if (someA)
	{
		someA->baz();
		someA->bar();
	}
}

int main(int argc, char* argv[])
{
	A someA;
	B someB;
	
	funcCaller(&someA);
	funcCaller(&someB);

	return 0;
}