#ifndef __EMPLOYEE_HPP
#define __EMPLOYEE_HPP

class Employee
{
    public:
        Employee();
    	Employee(char const * const name, char const * const position, double salary);
        Employee(const Employee& other);
        Employee(Employee&& other);

        ~Employee();

        Employee& operator=(const Employee& other);
        Employee& operator=(Employee&& other);

    	const char* GetName() const;
    	const char* GetPosition() const;
    	double GetSalary() const;

    	void SetName(char const * const name);
    	void SetPosition(char const * const position);
    	void SetSalary(double salary);

    	void Print() const;

    private:
    	char* name;
    	char* position;
    	double salary;

        void Copy(const Employee& other);
        void Deallocate();
};

#endif
