#ifndef __CLASS_HPP
#define __CLASS_HPP

#include "../Task2/Student.hpp"

const unsigned short MAX_NUM_OF_STUDENTS = 20;

class Class 
{
    public:
        Class();
        Class(const char* name);
        ~Class();

        const char* GetName() const;
        void SetName(const char* name);

        void AddStudent(const Student& student);
        void RemoveStudent(unsigned short classNumber);

        void DisplayInformation() const;
        double AverageScore() const;

        int CompareScores(const Class &other) const;

        const Student& GetStudent(unsigned short classNumber) const;

    private:
        unsigned short count;
        char* name;
        Student students[MAX_NUM_OF_STUDENTS];

        void CopyStudent(Student& dest, const Student& source);
};

#endif
