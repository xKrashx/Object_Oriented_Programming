#ifndef __CLASS_HPP
#define __CLASS_HPP

#include "../Task2/Student.hpp"

const unsigned short MAX_NUM_OF_STUDENTS = 20;

class Class 
{
    public:
        void Init(const char* name);
        void Deallocate();

        const char* GetName() const;
        void SetName(const char* name);

        void AddStudent(const Student& student);
        void RemoveStudent(unsigned short classNumber);

        void DisplayInformation() const;
        double AverageScore() const;

        int CompareScores(const Class &other) const;

        Student& GetStudent(unsigned short classNumber);

    private:
        unsigned short count = 0;
        char* name = nullptr;
        Student students[MAX_NUM_OF_STUDENTS];

        void CopyStudent(Student& dest, const Student& source);
};

#endif
