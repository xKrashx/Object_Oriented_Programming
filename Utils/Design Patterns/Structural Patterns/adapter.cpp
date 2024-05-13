#include <iostream>

class Target {
public:
    virtual void Print() = 0;
    virtual ~Target() = default;
};

class Adaptee {
public:
    virtual void PrintImpl() { std::cout << 1; }
    virtual ~Adaptee() = default;
};

class Adapter : public Target, public Adaptee {
public:
    void Print() override { Adaptee::PrintImpl(); }
};

int main() {
    Target *target = new Adapter;
    target -> Print();  // 1
    delete target;
    return 0;
}
