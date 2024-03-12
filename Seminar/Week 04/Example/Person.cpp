#include "Person.hpp"
#include <cstring>
#include <new>

void Person::Init(char const *name, unsigned age, Animal pet){

    this -> age = age;
    SetName(name);
    SetPet(pet);

}

void Person::SetName(char const *name){

    if(this -> name) Deallocate();
    this -> name = new(std::nothrow) char[strlen(name) + 1];
    strcpy(this -> name, name);

}
void Person::SetPet(Animal const pet){
    this -> pet.Init(pet.GetName(), pet.GetAge(), pet.GetType());
}

char const *Person::GetName() const{
    return name;
}
unsigned Person::GetAge() const{
    return age;
}
Animal Person::GetPet() const{
    return pet;
}

void Person::Deallocate(){
    delete[] name;
    name = nullptr;
}