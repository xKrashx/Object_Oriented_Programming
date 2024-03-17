#pragma once
#include "student.hpp"
#include <cstddef>

const size_t maxStudentsInClass = 40;

class Class{
    private:
    Student clas [maxStudentsInClass];
    size_t currentStudInClass = 0;
    
    public:
    bool StudentInClass(size_t numInClass)const;
    size_t getCurrNumINClass() const;
    void PrintClass() const;
    void addStudent(Student &student);
    void removeStudent(size_t numInClass);
    double AvarageGradeInClass() const;
    bool CompareAVGRadesInClasses(Class &other)const;
    Student FindStudent(size_t numInClass) const;
};
