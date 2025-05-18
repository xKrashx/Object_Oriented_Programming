#ifndef __FACTORY_HPP_
#define __FACTORY_HPP_

#include "../Student Types/Student.hpp"

enum class StudentType{
    LazyStudent,
    MotivatedStudent
};

Student *Factory(StudentType type, char const *name, size_t fn);

#endif