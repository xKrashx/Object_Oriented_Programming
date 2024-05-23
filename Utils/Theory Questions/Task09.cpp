/*
    Change the definition of class TypePrinter in such a way that it would be impossible for a descendant class to not define the method printClass
*/

#include <iostream>

class TypePrinter
{
public:
    virtual void printClass() {} // Children need to override this so it prints the correct class name
};

class A: public TypePrinter
{
};

int main(int argc, char* argv[])
{
    A a;
    a.printClass();

	return 0;
}