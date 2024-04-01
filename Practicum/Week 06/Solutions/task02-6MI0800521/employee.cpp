#include "employee.h"
#include <cstring>

void Employee::copy(const Employee &other)
{
    this->name = new(std::nothrow) char[strlen(other.name)];
    if (!this->name) return;
    strcpy(this->name,other.name);

    this->position = new(std::nothrow) char[strlen(other.position)];
    if (!this->position) return;
    strcpy(this->position,other.position);

    this->salary = other.salary;
}

void Employee::free()
{
    delete[] this->name;
    delete[] this->position;
}

bool Employee::isValidSalary(double salary)
{
    if (salary < 610 || salary > 4500)
    {
        std::cout << "Invalid salary!" << std::endl;
        return false;
    }
    return true;
}

Employee::Employee()
{
    this->name = new(std::nothrow) char[maxNameLenght];
    this->position = new(std::nothrow) char[maxPositionLenght];
    this->salary = 0;
}

Employee::Employee(const char *name, const char *position, const double salary)
{
    if(strlen(name) > maxNameLenght) return;
    this->name = new(std::nothrow) char[maxNameLenght];
    if(!this->name) return;
    strcpy(this->name, name);
    
    if(strlen(position) > maxPositionLenght) return;
    this->position = new(std::nothrow) char[maxPositionLenght];
    if(!this->position) return;
    strcpy(this->position, position);
    
    if (!isValidSalary(salary)) return;
    this->salary = salary;
}

Employee::Employee(const Employee &other)
{
    free();
    copy(other);
}

Employee &Employee::operator=(const Employee &other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

Employee::Employee(Employee &&other)
{
    free();
    this->name = other.name;
    this->position = other.position;
    this->salary = other.salary;
    other.name = nullptr;
    other.position = nullptr;
    other.salary = 0;
}

Employee& Employee::operator=(Employee &&other)
{
    if (this != &other)
    {
        free();
        this->name = other.name;
        this->position = other.position;
        this->salary;
        other.name = nullptr;
        other.position = nullptr;
        other.salary = 0;
    }
    
    return *this;
}

Employee::~Employee()
{
    free();
}

void Employee::SetName(const char* name)
{
   if(strlen(name) > maxNameLenght) return;
   
   delete[] this->name;
   this->name = new(std::nothrow) char[strlen(name) + 1];
   if(!this->name) return;
   strcpy(this->name, name);
}

void Employee::SetPosition(const char* position)
{
    if(strlen(position) > maxPositionLenght) return;
    
    delete[] this->position;
    this->position = new(std::nothrow) char[strlen(position) + 1];
    if(!this->position) return;
    strcpy(this->position, position);
}

void Employee::SetSalary(double salary)
{
    if(!isValidSalary(salary)) return;
    
    this->salary = salary;
}

const char* Employee::GetName()
{
    return this->name;
}

const char* Employee::GetPosition()
{
    return this->position;
}

const double Employee::GetSalary()
{
    return this->salary;
}

void Employee::Print()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Position: " << this->position << std::endl;
    std::cout << "Salary: " << this->salary << std::endl;
}
