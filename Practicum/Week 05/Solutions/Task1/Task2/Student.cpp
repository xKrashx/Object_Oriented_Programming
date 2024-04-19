#include <iostream>
#include <cstring>

#include "Student.hpp"

const unsigned short MAX_NUM_OF_STUDENTS = 20;
const unsigned short MAX_LEN = 255;

Student::Student() : name(nullptr), classNumber(1)
{
    for(unsigned i = 0; i < NUM_GRADES; i++)
    {
        this->grades[i] = 2.00;
    }
}

Student::Student(const char* name, unsigned short classNumber)
    : name(nullptr), classNumber(1)
{
    this->SetName(name);
    this->SetClassNumber(classNumber);

    for(unsigned i = 0; i < NUM_GRADES; i++)
    {
        this->grades[i] = 2.00;
    }
}

Student::~Student()
{
    delete[] this->name;
    this->name = nullptr;
}

const char* Student::GetName() const
{
    return this->name;
}

unsigned short Student::GetClassNumber() const
{
    return this->classNumber;
}

double Student::GetGrade(unsigned short index) const
{
    if(index < NUM_GRADES)
    {
        return this->grades[index];
    }

    std::cout << "Invalid index!" << std::endl;
    return 2.00;
}

void Student::SetName(const char* name)
{
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

void Student::SetClassNumber(unsigned short classNumber)
{
    if(classNumber <= MAX_NUM_OF_STUDENTS)
    {
        this->classNumber = classNumber;
    }
    else
    {
        std::cout << "Invalid class number!" << std::endl;
    }
}

void Student::SetGrade(unsigned short index, double newGrade)
{
    if(index < NUM_GRADES && newGrade >= 2.00 && newGrade <= 6.00)
    {
        this->grades[index] = newGrade;
    }
    else
    {
        std::cout << "Invalid data!" << std::endl;
    }
}

void Student::Read()
{
    std::cout << "name: ";
    
    char name[MAX_LEN];
    std::cin.getline(name, MAX_LEN);
    this->SetName(name);

    std::cout << "class number: ";

    unsigned short classNumber;
    std::cin >> classNumber;
    this->SetClassNumber(classNumber);

    std::cout << NUM_GRADES << " grades:" << std::endl;

    for(unsigned i = 0; i < NUM_GRADES; i++)
    {
        double grade;
        std::cin >> grade;
        this->SetGrade(i, grade);
    }
}

void Student::Print() const
{
    std::cout << "name: "             << this->name 
              << ", class number: "   << this->classNumber
              << ", average grade: "  << this->AverageGrade()
              << std::endl;
}

double Student::AverageGrade() const
{
    double sum = 0;
    for(unsigned i = 0; i < NUM_GRADES; i++)
    {
        sum += this->grades[i];
    }
    return sum / NUM_GRADES;
}

int Student::Compare(const Student& other) const
{
    const double EPS = 0.01;
    double result = this->AverageGrade() - other.AverageGrade();

    if(std::abs(result) < EPS) return 0;
    else if(result < 0) return -1;
    return 1;
}
