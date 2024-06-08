/*
    Write a comment to explain the output
*/

/*
The result of execution is the following:
Calling A::baz() 
Calling A::bar()
Calling A::baz()
Calling B::bar()

This is because A::bar is virtual and it is added to the Vtable and A::baz is not.
So when passing arguments as A* the compiler thinks that it should call the A::baz function all the time.
As for the bar function it is virtual so it knows when to call the A::bar and B::bar function respectfully.
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