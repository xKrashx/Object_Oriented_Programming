#pragma once
#include "Animal.hpp"

class Person{

public:
    void Init(char const *name, unsigned age, Animal pet);

    void SetName(char const *name);
    void SetPet(Animal const pet);

    char const *GetName() const;
    unsigned GetAge() const;
    Animal GetPet() const;

    void Deallocate();

private:
    char *name = nullptr;
    unsigned age = 0;
    Animal pet;

};