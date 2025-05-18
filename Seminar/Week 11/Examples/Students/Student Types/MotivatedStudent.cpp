#include "MotivatedStudent.hpp"

MotivatedStudent::MotivatedStudent(char const *name, size_t fn): Student(name, fn){}

double MotivatedStudent::PercentageToPassTheExam() const{
    return 0.75;
}

unsigned MotivatedStudent::HoursSpentPerDayStudying() const{
    return 16;
}

Student *MotivatedStudent::Clone() const{
    return new MotivatedStudent(*this);
}