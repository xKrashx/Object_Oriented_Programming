#include "Animal.hpp"
#include <iostream>
#include <cstring>

void Animal::Init(char const *name, unsigned age, Type type){

    this -> age = age;
    this -> type = type;
    SetName(name);

}

void Animal::Speak(){

    switch (type)
    {
    case Animal::Type::Dog:
        std::cout << "Bow wou\n";
        break;
    
    case Animal::Type::Cat:
        std::cout << "Meow meow\n";
        break;
    
    case Animal::Type::Fish:
        std::cout << "brrrrr\n";
        break;
    
    case Animal::Type::Monkey:
        std::cout << "U Agh U agh\n";
        break;
    
    default:
        break;
    }

}
void Animal::SetName(char const *name){

    if(this -> name) Deallocate();
    this -> name = new(std::nothrow) char[strlen(name) + 1];
    strcpy(this -> name, name);

}

char const *Animal::GetName() const{
    return name;
}
unsigned Animal::GetAge() const{
    return age;
}
Animal::Type Animal::GetType() const{
    return type;
}

void Animal::Deallocate(){
    delete[] name;
    name = nullptr;
}