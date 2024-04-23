#ifndef __COMPANY_HPP
#define __COMPANY_HPP

#include "../Task1/Employee.hpp"

class Company
{
    public:
        Company();
    	Company(char const * const name);
        Company(const Company& other);
        Company(Company&& other);

        ~Company();

        Company& operator=(const Company& other);
        Company& operator=(Company&& other);

    	const char* GetName() const;
    	unsigned short GetNumberOfEmployees() const;

        void SetName(char const * const name);

        void AppointAnEmployee(const Employee& employee);
        void FiredAnEmployee(char const * const name);

        void Print() const;

    private:
        char* name;
        Employee* employees;
        unsigned short capacity;
        unsigned short numberOfEmployees;

        void Allocate(const unsigned short size);
        void Copy(const Company& other);
        void Move(Company&& other);
        void Deallocate();
        void Resize();

        void SetNumberOfEmployees(unsigned short numberOfEmployees);
        void SetCapacity(unsigned short capacity);

};

#endif
