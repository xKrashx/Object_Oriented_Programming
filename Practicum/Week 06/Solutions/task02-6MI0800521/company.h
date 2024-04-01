#pragma once
#include "employee.h"
#include <iostream>

class Company
{
private:
    const size_t maxEmployeeCount = 150;
    const size_t maxNameLenght = 50;

    char* companyName;
    unsigned int employeeCount;
    Employee* employees;

    void copy(const Company& other);
    void free();
    bool cmpr(const char* str1, const char* str2);
    // unsigned int get
public:
    Company();
    Company(const char* name, const Employee* employees);
    Company(const Company& other);
    Company& operator=(const Company& other);
    Company(Company&& other);
    Company& operator=(Company&& other);
    ~Company();
    void AddEmployee(const Employee& newEmployee);
    void RemoveEmployee(const char* employeeName);
    void Print();
};
