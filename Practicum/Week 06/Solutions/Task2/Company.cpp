#include "Company.hpp"

#include <iostream>
#include <cstring>
#include <new>

const unsigned short MAX_NAME_LEN = 50;
const unsigned short CAPACITY = 512;

const unsigned short INITIAL_CAPACITY = 2;
const unsigned short INCREASE_STEP = 2;

Company::Company() 
    : name(nullptr), employees(nullptr), capacity(0), numberOfEmployees(0)
{ }

Company::Company(char const * const name)
    : name(nullptr), employees(nullptr), capacity(0), numberOfEmployees(0)
{
    this->SetName(name);
    this->Allocate(INITIAL_CAPACITY);
    this->SetCapacity(INITIAL_CAPACITY);
}

Company::Company(const Company& other) 
    : name(nullptr), employees(nullptr), capacity(0), numberOfEmployees(0)
{
    this->Copy(other);
}

Company::Company(Company&& other)
    : name(nullptr), employees(nullptr), capacity(0), numberOfEmployees(0)
{
    this->Move(std::move(other));
}

Company::~Company()
{
    this->Deallocate();
}

Company& Company::operator=(const Company& other)
{
    if(this != &other)
    {
        this->Deallocate();
        this->Copy(other);
    }
    return *this;
}

Company& Company::operator=(Company&& other)
{
    if(this != &other)
    {
        this->Deallocate();
        this->Move(std::move(other));
    }
    return *this;
}

const char* Company::GetName() const
{
    return this->name;
}

unsigned short Company::GetNumberOfEmployees() const
{
    return this->numberOfEmployees;
}

void Company::SetName(char const * const name)
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

void Company::SetNumberOfEmployees(unsigned short numberOfEmployees)
{
    if(numberOfEmployees > capacity)
    {
        std::cout << "Invalid number of employees!" << std::endl;
        return;
    }
    this->numberOfEmployees = numberOfEmployees;
}

void Company::SetCapacity(unsigned short capacity)
{
    if(capacity > CAPACITY)
    {
        std::cout << "Invalid capacity!" << std::endl;
        return;
    }
    this->capacity = capacity;
}

void Company::AppointAnEmployee(const Employee& employee)
{
    if(this->numberOfEmployees + 1 <= this->capacity)
    {
        this->employees[this->numberOfEmployees] = employee;
        this->SetNumberOfEmployees(this->numberOfEmployees + 1);
    }
    else if(this->capacity * INCREASE_STEP <= CAPACITY)
    {
        this->Resize();
        this->employees[this->numberOfEmployees] = employee;
        this->SetNumberOfEmployees(this->numberOfEmployees + 1);
    }
    else
    {
        std::cout << "The company is full!" << std::endl;
    }
}

void Company::FiredAnEmployee(char const * const name)
{
    if(this->numberOfEmployees == 0) return;

    for(unsigned short i = 0; i < this->numberOfEmployees; i++)
    {
        if(strcmp(this->employees[i].GetName(), name) == 0)
        {
            Employee temp(this->employees[i]);
            this->employees[i] = this->employees[this->numberOfEmployees - 1];
            this->employees[this->numberOfEmployees - 1] = temp;

            this->SetNumberOfEmployees(this->numberOfEmployees - 1);

            break;
        }
    }
}

void Company::Print() const
{
    std::cout << "company name: "       << (this->name ? this->name : "")  << std::endl
              << "number of employees: " << this->numberOfEmployees         << std::endl
              << "employees:\n";
    
    for(unsigned short i = 0; i < numberOfEmployees; i++)
    {
        this->employees[i].Print();
        std::cout << "----------------------------------\n";
    }
}

void Company::Allocate(const unsigned short size)
{
    this->employees = new(std::nothrow) Employee[size];
    if(!this->employees)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
}

void Company::Copy(const Company& other)
{
    this->SetName(other.name);
    this->Allocate(other.capacity);

    for(unsigned short i = 0; i < other.numberOfEmployees; i++)
    {
        this->employees[i] = other.employees[i];
    }

    this->SetNumberOfEmployees(other.numberOfEmployees);
    this->SetCapacity(other.capacity);
}

void Company::Move(Company&& other)
{
    this->name = other.name;
    other.name = nullptr;

    this->employees = other.employees;
    other.employees = nullptr;

    this->capacity = other.capacity;
    other.capacity = 0;

    this->numberOfEmployees = other.numberOfEmployees;
    other.numberOfEmployees = 0;
}

void Company::Deallocate()
{
    delete[] this->name;
    this->name = nullptr;

    delete[] this->employees;
    this->employees = nullptr;
}

void Company::Resize()
{
    Employee* newArray = new(std::nothrow) Employee[this->capacity * INCREASE_STEP];
    if(!newArray)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }

    for(unsigned short i = 0; i < this->numberOfEmployees; i++)
    {
        newArray[i] = this->employees[i]; 
    }

    this->Deallocate();

    this->capacity *= INCREASE_STEP;

    this->employees = newArray;
    newArray = nullptr;
}
