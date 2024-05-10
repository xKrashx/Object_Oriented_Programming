#include "company.h"
#include <cstring>

void Company::copy(const Company &other)
{
    this->companyName = new(std::nothrow) char[maxNameLenght];
    if(!this->companyName) return;
    strcpy(this->companyName,other.companyName);

    this->employeeCount = other.employeeCount;

    this->employees = new(std::nothrow) Employee[maxEmployeeCount];
    if(this->employees) return;
    for (size_t i = 0; i < this->employeeCount; i++)
    {
        this->employees[i] = other.employees[i];
    }
}

void Company::free()
{
    delete[] this->companyName;
    delete[] this->employees;
}

bool Company::cmpr(const char* str1, const char* str2)
{
    if (strlen(str1) != strlen(str2)) return false;
    
    for (size_t i = 0; i < strlen(str2); i++)
    {
        if (str1[i] != str2[i]) return false;
    }
    
    return true;
}

Company::Company()
{
    this->companyName = new(std::nothrow) char[maxNameLenght];
    if(!this->companyName) return;
    this->employeeCount = 0;
    this->employees = new(std::nothrow) Employee[maxEmployeeCount];
    if(this->employees) return;
}

Company::Company(const char *name, const Employee *employees)
{
    if(strlen(name) > maxNameLenght) return;
    this->companyName = new(std::nothrow) char[strlen(name) + 1];
    if(!companyName) return;

    //this->employeeCount = sizeof(employees) / sizeof(Employee);
    this->employeeCount = *(&employees + 1) - employees;

    this->employees = new(std::nothrow) Employee[this->employeeCount];
    for (size_t i = 0; i < employeeCount; i++)
    {
        this->employees[i] = employees[i];
    }
}
Company::Company(const Company &other)
{
    this->free();
    this->copy(other);
}

Company &Company::operator=(const Company &other)
{
    if (this != &other)
    {
        this->free();
        this->copy(other);
    }
    return *this;
}

Company::Company(Company &&other)
{
    if (this->companyName) delete[] this->companyName;
    
    this->companyName = other.companyName;
    other.companyName = nullptr;

    if (this->employees) delete[] this->employees;
    
    this->employees = other.employees;
    other.employees = nullptr;

    this->employeeCount = other.employeeCount;
}

Company &Company::operator=(Company &&other)
{
    if (this != &other)
    {
        if (this->companyName) delete[] this->companyName;
    
        this->companyName = other.companyName;
        other.companyName = nullptr;

        if (this->employees) delete[] this->employees;
        
        this->employees = other.employees;
        other.employees = nullptr;

        this->employeeCount = other.employeeCount;
    }
    return *this;
}

Company::~Company()
{
    this->free();
}

void Company::AddEmployee(const Employee &newEmployee)
{
    this->employees[employeeCount] = newEmployee;
    employeeCount++;
}

void Company::RemoveEmployee(const char* employeeName)
{
    Employee* newArray = new(std::nothrow) Employee[this->employeeCount];
    if(!newArray) return;
    
    size_t index = 0;
    for (size_t i = 0; i < employeeCount; i++)
    {
        if (cmpr(this->employees[i].GetName(), employeeName))
        {
            index = i;
            break;
        }else
        {
            newArray[i] = this->employees[i];
            index = -1;
        }
    }
    
    if (index == -1)
    {
        std::cout << "There is not employee whit that name!" << std::endl;
        return;
    }
    
    for (size_t i = index; i < employeeCount; i++)
    {
        newArray[i] = this->employees[i + 1];
    }
    
    delete[] this->employees;
    this->employees = newArray;
    this->employeeCount--;
}

void Company::Print()
{
    for (size_t i = 0; i < employeeCount; i++)
    {
        this->employees[i].Print();
        std::cout << std::endl;
    }
}
