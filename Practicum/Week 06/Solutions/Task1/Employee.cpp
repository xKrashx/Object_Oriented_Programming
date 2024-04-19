#include "Employee.hpp"

#include <iostream>
#include <cstring>
#include <new>

const unsigned short MAX_NAME_LEN = 150;
const unsigned short MAX_POS_LEN = 20;
const double         MIN_SALARY = 610;
const double         MAX_SALARY = 4500;

Employee::Employee() 
    : name(nullptr), position(nullptr), salary(MIN_SALARY)
{ }

Employee::Employee(char const * const name, char const * const position, double salary)
     : name(nullptr), position(nullptr), salary(MIN_SALARY)
{
    this->SetName(name);
    this->SetPosition(position);
    this->SetSalary(salary);
}

Employee::Employee(const Employee& other) 
    : name(nullptr), position(nullptr), salary(MIN_SALARY)
{
    this->Copy(other);
}

Employee::Employee(Employee&& other)
    : name(other.name), position(other.position), salary(other.salary)
{
    other.name = nullptr;
    other.position = nullptr;
    other.salary = MIN_SALARY;
}

Employee::~Employee()
{
    this->Deallocate();
}

Employee& Employee::operator=(const Employee& other)
{
    if(this != &other)
    {
        this->Deallocate();
        this->Copy(other);
    }
    return *this;
}

Employee& Employee::operator=(Employee&& other)
{
    if(this != &other)
    {
        this->Deallocate();
        
        this->name = other.name;
        other.name = nullptr;
    
        this->position = other.position;
        other.position = nullptr;
    
        this->salary = other.salary;
        other.salary = MIN_SALARY;
    }
    return *this;
}

const char* Employee::GetName() const
{
    return this->name;
}

const char* Employee::GetPosition() const
{
    return this->position;
}

double Employee::GetSalary() const
{
    return this->salary;
}

void Employee::SetName(char const * const name)
{
    unsigned short nameLen = strlen(name);

    if(!name || nameLen > MAX_NAME_LEN) 
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

void Employee::SetPosition(char const * const position)
{
    unsigned short positionLen = strlen(position);

    if(!position || positionLen > MAX_POS_LEN) 
    {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    delete[] this->position;

    this->position = new(std::nothrow) char[positionLen + 1];
    if(!this->position)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }

    strcpy(this->position, position);
}

void Employee::SetSalary(double salary)
{
    if(salary < MIN_SALARY || salary > MAX_SALARY)
    {
        std::cout << "Invalid salary!" << std::endl;
        return;
    }

    this->salary = salary;
}

void Employee::Print() const
{
    std::cout << "name: "     << (this->name ? this->name : "")         << std::endl
              << "position: " << (this->position ? this->position : "") << std::endl
              << "salary: "   << this->salary                           << std::endl;
}

void Employee::Copy(const Employee& other)
{
    this->SetName(other.name);
    this->SetPosition(other.position);
    this->SetSalary(other.salary);
}

void Employee::Deallocate()
{
    delete[] this->name;
    this->name = nullptr;

    delete[] this->position;
    this->position = nullptr;
}
