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