#include "Factory.hpp"
#include "../Student Types/LazyStudent.hpp"
#include "../Student Types/MotivatedStudent.hpp"

Student *Factory(StudentType type, char const *name, size_t fn){

    switch (type){
    case StudentType::LazyStudent: return new LazyStudent(name, fn);
    case StudentType::MotivatedStudent: return new MotivatedStudent(name, fn);
    
    default: return nullptr;
    }

}