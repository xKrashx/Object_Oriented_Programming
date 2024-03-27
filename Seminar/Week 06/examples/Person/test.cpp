#include <iostream>
#include "Person.hpp"

int main(){

    Person p("Hristo", "Kanev", 20), p1;

    p1 = p;

    std::cout << p1.getName() << ' ' << p1.getSurname() << ' ' << p1.getAge() << '\n';

    return 0;

}