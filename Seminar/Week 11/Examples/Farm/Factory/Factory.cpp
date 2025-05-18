#include "Factory.hpp"
#include "../Animals/Cat.hpp"
#include "../Animals/Dog.hpp"
#include "../Animals/Mouse.hpp"

Animal *Factory(AnimalType type){

    switch (type){

        case AnimalType::Cat: return new Cat;
        case AnimalType::Dog: return new Dog;
        case AnimalType::Mouse: return new Mouse;
        
        default: return nullptr;

    }

}