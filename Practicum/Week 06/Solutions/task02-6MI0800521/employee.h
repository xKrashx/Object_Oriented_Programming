#pragma once
#include <iostream>

class Employee
{
private:
    char* name;
    char* position;
    double salary;

    void copy(const Employee& other);
    void free();
    bool isValidSalary(double salary);
    const size_t maxNameLenght = 150;
    const size_t maxPositionLenght = 20;
public:
    Employee();
    Employee(const char* name, const char* position, const double salary);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    Employee(Employee&& other);
    Employee& operator=(Employee&& other);
    ~Employee();
    void SetName(const char* name);
    void SetPosition(const char* position);
    void SetSalary(const double salary);
    const char* GetName();
    const char* GetPosition();
    const double GetSalary();
    void Print();
};

