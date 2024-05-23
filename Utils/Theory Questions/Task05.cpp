/*
    Fix the problem with the code below
    Write a comment to explain the output
*/

#include <iostream>

class A
{
public:
    A(): m_AData(new int()) { std::cout << "Calling A::A() " << std::endl; }
    ~A()                    { std::cout << "Calling A::~A() " << std::endl; delete m_AData; }
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
    delete someA;
    B b;

	return 0;
}