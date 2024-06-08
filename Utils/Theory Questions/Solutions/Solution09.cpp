/*
    Change the definition of class TypePrinter in such a way that it would be impossible for a descendant class to not define the method printClass
*/

#include <iostream>

class TypePrinter
{
public:
    // It is done by adding = 0 at the end of the definition and making it a pure virtual function.
    virtual void printClass() = 0; // Children need to override this so it prints the correct class name
};

class A: public TypePrinter
{
public:
    void printClass() override{
        std::cout << "A\n";
    }
};

int main(int argc, char* argv[])
{
    A a;
    a.printClass();

	return 0;
}