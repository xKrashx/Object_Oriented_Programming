#include <iostream>
#include "Person.hpp"

int main(){

    Animal a;
    a.Init("Penka", 3, Animal::Type::Cat);
    Animal b;
    b.Init("Toshko", 7, Animal::Type::Dog);

    Person p;
    p.Init("Gosho", 10, a);

    p.GetPet().Speak();

    p.SetPet(b);
    p.GetPet().Speak();

    std::cout << p.GetPet().GetName() << '\n';

    p.Deallocate();
    a.Deallocate();
    b.Deallocate();
    return 0;

}