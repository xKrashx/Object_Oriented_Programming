#include <iostream>
#include <string>
#include "MyClass.h"

int getValue()
{
    return 42;
}

int &getValue1()
{
    static int a = 42;
    return a;
}

void setValue(int value)
{
}

void setValue1(int &value)
{
}

void printName(std::string &name)
{
    std::cout << "lvalue: " << name << std::endl;
}

void printName(const std::string &name)
{
    std::cout << name << std::endl;
}

void printName(const std::string &&name)
{
    std::cout << "rvalue: " << name << std::endl;
}

int main()
{
    // lvalue is something that points to a specific memory location
    int i = 10;
    // rvalue is something that doesn't point anywhere.
    // rvalues are temporary and short lived, while lvalues live a longer life since they exist as variables.
    //  i is lvalue, 10 is r value
    // 10 = i; //не

    // ravlue is always on the right side, lvalue is not always on the left side
    int a = i;
    i = getValue();
    // getValue() = i; //не
    getValue1() = i;

    setValue(i);
    setValue(10);

    setValue1(i);
    // setValue1(10); //no
    // const int& a = 10; same as int temp = 10; const int& a = temp;

    //.......................//.......................//.......................//.......................//.......................//.......................
    std::string firstName = "Hristo";
    std::string lastName = "Kanev";
    std::string fullName = firstName + lastName;
    printName(fullName);
    // workaround void printName(const std::string& name)
    printName(firstName + lastName);
    // void printName(const std::string& name) is not being called, always the specific ones are chosen
    //.......................//.......................//.......................//.......................//.......................//.......................
    MyClass mc1;
    MyClass mc2;
    mc1 = mc2;
    mc2 = MyClass::createMyClass();
    mc2 = std::move(mc1);
    /*std::move:
    template <typename T>
    std::remove_reference_t<T>&& move(T && t) noexcept {
        return static_cast<typename std::remove_reference<T>::type&&>(t);
    }*/
}