#ifndef __FACTORY_HPP_
#define __FACTORY_HPP_

#include "../Animals/Animal.hpp"

enum class AnimalType{
    Cat,
    Dog,
    Mouse
};

Animal *Factory(AnimalType type);

#endif