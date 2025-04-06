#include <iostream>
#include <cstring>
#include <fstream>

// friend classes
class A
{
private:
    int a;

public:
    A() { a = 0; }
    friend class B; // Friend Class
};

// forward declaration
class C;

class B
{
private:
    int b;

public:
    B() { b = 1; }
    void showA(A &x)
    {
        // Since B is friend of A, it can access
        // private members of A
        std::cout << "A::a = " << x.a << std::endl;
    }
    void showC(C &x); // Friend function
};

// forward declaration
class C
{
private:
    int c;

public:
    C() { c = 2; }
    friend void B::showC(C &x); // Friend function
    C Add(const C &other)
    {
        C c;
        c.c = this->c + other.c;
        return c;
    }
    C Add(int num)
    {
        C c;
        c.c = this->c + num;
        return c;
    }
    friend C Add(int num, const C &c);
    void setC(int c)
    {
        this->c = c;
    }
};

C Add(int num, const C &rhs)
{
    C c;
    c.c = rhs.c + num;
    return c;
}

void B::showC(C &x)
{
    // Since showC() is friend of C, it can
    // access private members of C
    std::cout << "C::c = " << x.c << std::endl;
}

int main()
{
    // friend classes
    A a;
    B b;
    C c1;
    C c2;
    c2.setC(10);
    C c3 = c1.Add(c2);
    C c4 = c1.Add(5);
    C c5 = Add(6, c1);
    b.showA(a);
    b.showC(c3);
    b.showC(c4);
    b.showC(c5);

    return 0;
}