/*
    Fix the problem with the code below
    Write a comment to explain the output
*/

#include <iostream>

class A
{
public:
    A(): m_AData(new int()) { std::cout << "Calling A::A() " << std::endl; }
    virtual ~A()            { std::cout << "Calling A::~A() " << std::endl; delete m_AData; } // Destructor should be virtual!!!
private:
    int* m_AData;
};

class B : public A
{
public:
    B(): m_BData(new int()) { std::cout << "Calling B::B() " << std::endl;}
    ~B()                    { std::cout << "Calling B::~B() " << std::endl; delete m_BData; }
private:
    int* m_BData;
};

int main(int argc, char* argv[])
{
    A* someA = new B();
    // Problem here is that when we call delete on a pointer of type A, it doesn't know of the existance of B's extension.
    // Thus we have to mark the destructor of A virtual, so it creates a Vtable, that can navigate to the correct destructor.
    delete someA;

    // Here it is fine as it is, because it is of type B and it knows about its destructor.
    B b;

	return 0;
}