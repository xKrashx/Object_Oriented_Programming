/*
    Fix the problem with the code below. Write a comment explaining the cause.
*/

#include <iostream>

struct A
{
    A() { initData(); }

    virtual void initData() { m_data = 5; }
    virtual void processData() { m_data += 5; }

    int m_data;
};

struct B: public A
{
    // B was missing a default constructor.
    // This means that the compiler generates its own default constructor, which does not call initData.
    // On the other hand a derived class must call it's parents constructor.
    // Thus we call A() first which calls A::initData() and makes m_data = 5.
    // The order of calls is B() -> A() -> A::initData() -> B::initData(). And than m_data = 6.
    B() { initData(); }
    virtual void initData() { m_data = 6; }
    virtual void processData() { m_data += 4; }
};

int main(int argc, char* argv[])
{
    A a;
    B b;
    a.processData();
    b.processData();
    std::cout << a.m_data << std::endl;
    std::cout << b.m_data << std::endl;

	return 0;
}