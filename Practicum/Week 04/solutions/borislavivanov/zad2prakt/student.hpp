#pragma once
#include <cstddef>
const size_t nameLenght = 40;
const size_t numGrades = 5;
class Student
{
    private:    
    
    size_t numInClass;
    char name [nameLenght] = {' ',};
    double subjectsGrades [numGrades];

    public:
    
    void InputStudent();
    void OutputStudent() const;
    double AvarageGrade() const;
    const char* getName() const;
    size_t getNumInClass() const;
    const double* getSubjectGrades(size_t i) const;
    void setName(const char* Name);
    void setNumInClass(size_t num);
    void setSubjectsGrades(int grades[]);
    bool compareAvarageGrades(Student &other)const;
    void Print()const;
};