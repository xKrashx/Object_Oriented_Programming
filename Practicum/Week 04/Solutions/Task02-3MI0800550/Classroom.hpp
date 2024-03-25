#pragma once
#include "Student.hpp"

const size_t NUM_OF_STUDENTS = 20;

class Classroom
{
private:
    Student *students;
    size_t taken_places = 0;
public:
    Classroom();
    ~Classroom(){delete[] students;}

    
    unsigned int GetStudentNumber(Student &student);
    void AddStudent(Student &student);
    Student GetStudentByNumber(unsigned int number);
    double GetAverageClassGrade();
    bool CompareAverages(Classroom &other);

    void PrintStudents();
};

