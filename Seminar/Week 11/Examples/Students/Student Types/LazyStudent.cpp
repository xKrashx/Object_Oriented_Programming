#include "LazyStudent.hpp"

LazyStudent::LazyStudent(char const *name, size_t fn): Student(name, fn){}

double LazyStudent::PercentageToPassTheExam() const{
    return 0.2;
}

unsigned LazyStudent::HoursSpentPerDayStudying() const{
    return 1;
}

Student *LazyStudent::Clone() const{
    return new LazyStudent(*this);
}