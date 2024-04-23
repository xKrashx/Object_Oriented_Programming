#include "Class.hpp"

#include <iostream>
#include <cstring>

Class::Class() : name(nullptr), count(0)
{ }

Class::Class(const char* name) : name(nullptr), count(0)
{
    this->SetName(name);
}

Class::~Class() 
{
    delete[] this->name;
    this->name = nullptr;
}

const char* Class::GetName() const
{
    return this->name;
}

void Class::SetName(const char* name)
{
    const unsigned short MAX_LEN = 255;
    unsigned short nameLen = strlen(name);

    if(!name || nameLen > MAX_LEN)
    {
        std::cout << "Invalid name!" << std::endl;
        return;
    }

    delete[] this->name;

    this->name = new(std::nothrow) char[nameLen + 1];
    if(!this->name)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(this->name, name);
}

void Class::AddStudent(const Student& student) 
{
    if(this->count >= MAX_NUM_OF_STUDENTS)  
    {
        std::cerr << "The class is full!" << std::endl;
        return;
    }

    unsigned short i = 0, write = this->count;
    int read = this->count - 1;
    bool added = false;

    while(read >= 0 && !added)
    {
        if(strcmp(student.GetName(), this->students[read].GetName()) < 0)
        {
            this->CopyStudent(this->students[write], this->students[read]);
            this->students[write].SetClassNumber(write + 1);
            read--; write--;
        }
        else
        {
            this->CopyStudent(this->students[write], student);
            this->students[write].SetClassNumber(write + 1);
            this->count++;
            added = true;
        }
    }

    if(!added)
    {
        this->CopyStudent(this->students[0], student);
        this->count++;
    }
}

void Class::RemoveStudent(unsigned short classNumber) 
{
    if(this->count == 0)
    {
        std::cerr << "The class is empy!" << std::endl;
        return;
    }

    if(classNumber == 0 || classNumber > this->count)
    {
        std::cerr << "Invalid class number!" << std::endl;
        return;
    }

    for(unsigned i = classNumber - 1; i < this->count - 1; i++)
    {
        this->CopyStudent(this->students[i], this->students[i + 1]);
        this->students[i].SetClassNumber(i + 1);
    }
    this->count--;
}

void Class::DisplayInformation() const 
{
    std::cout << "class name: " << this->name << std::endl;
    std::cout << "number of students: " << this->count << std::endl;
    std::cout << "students: " << std::endl;
    for (int i = 0; i < count; i++) 
    {
        students[i].Print();
    }
}

double Class::AverageScore() const 
{
    if(this->count == 0)
    {
        std::cerr << "Class is empy!" << std::endl;
        return 2.00;
    }

    double sum = 0;
    for (int i = 0; i < count; i++) 
    {
        sum += students[i].AverageGrade();
    }
    return sum / this->count;
}

int Class::CompareScores(const Class& other) const 
{
    const double EPS = 0.01;
    double result = this->AverageScore() - other.AverageScore();

    if(std::abs(result) < EPS) return 0;
    else if(result < 0) return -1;
    return 1;
}

const Student& Class::GetStudent(unsigned short classNumber) const 
{
    if(classNumber <= this->count) 
    {
        return this->students[classNumber - 1];
    }
    
    std::cerr << "Invalid class number!" << std::endl;
    return this->students[0];
}

void Class::CopyStudent(Student& dest, const Student& source)
{
    dest.SetName(source.GetName());
    dest.SetClassNumber(source.GetClassNumber());

    for(unsigned i = 0; i < NUM_GRADES; i++)
    {
        dest.SetGrade(i, source.GetGrade(i));
    }
}
