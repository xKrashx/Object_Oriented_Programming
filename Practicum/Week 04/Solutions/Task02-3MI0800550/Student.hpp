#pragma once
#include <iostream>
#include <cstring>

const size_t NUM_OF_SUBJECTS = 5;
const size_t SIZE = 100;

struct Grade
{
    char Subject[SIZE];
    double mark;
};
 
class Student
{
private:
    char name[SIZE];
    unsigned int number;
    Grade grades[NUM_OF_SUBJECTS] = {{"Math", 0},
                                     {"English", 0}, 
                                     {"Geometry", 0}, 
                                     {"PE", 0}, 
                                     {"Literature", 0}};

public:
    
    Student(const char* new_name = "");
    void SetNumber(unsigned int number);
    void SetGrade(Grade grade);

    char* GetName();
    unsigned int GetNumber();
    double GetGrade(char *subject);
    double GetAverageGrade();
    
    void PrintAllGrades();

    bool operator==(Student &student);
};

