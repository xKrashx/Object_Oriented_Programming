#include <iostream>
#include <new>

class AbstractionImpl {
public:
    virtual void PrintImpl() = 0;
    virtual ~AbstractionImpl() = default;
};

class AImpl1 : public AbstractionImpl {
public:
    void PrintImpl() override { std::cout << 1; }
};

class AImpl2 : public AbstractionImpl {
public:
    void PrintImpl() override { std::cout << 2; }
};

class Abstraction {
public:
    virtual void Print() = 0;
    virtual ~Abstraction() = default;
};

class A1 : public Abstraction {
public:
    explicit A1(AbstractionImpl *impl) : m_Impl(std::move(impl)) {}

    void Print() override { m_Impl->PrintImpl(); }

    ~A1() override{ delete m_Impl; }

private:
    AbstractionImpl *m_Impl;
};

class A2 : public Abstraction {
public:
    explicit A2(AbstractionImpl *impl) : m_Impl(std::move(impl)) {}

    void Print() override { m_Impl->PrintImpl(); }

    ~A2() override{ delete m_Impl; }

private:
    AbstractionImpl *m_Impl;
};

int main() {
    Abstraction *a1 = (A1 *)(new(std::nothrow) AImpl1);
    Abstraction *a2 = (A1 *)(new(std::nothrow) AImpl2);
    Abstraction *a3 = (A2 *)(new(std::nothrow) AImpl1);
    Abstraction *a4 = (A2 *)(new(std::nothrow) AImpl2);

    if(!a1 || !a2 || !a3 || !a4){

        delete a1;
        delete a2;
        delete a3;
        delete a4;

        return 0;

    }

    a1 -> Print();  // 1
    a2 -> Print();  // 2
    a3 -> Print();  // 1
    a4 -> Print();  // 2

    delete a1;
    delete a2;
    delete a3;
    delete a4;

    return 0;
}
