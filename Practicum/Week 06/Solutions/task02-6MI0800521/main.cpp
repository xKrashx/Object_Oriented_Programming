#include "company.h"

int main()
{
    Company comp;
    Employee emp1("Ivan", "developer", 3356);
    Employee emp2("Petar", "developer", 2159);
    Employee emp3("Georgi", "developer", 1567);
    Employee emp4("Kalin", "developer", 2245);
    Employee emp5("Stoyan", "developer", 3100);
    Employee emp6("Ema", "developer", 700);
    Employee emp7("Geri", "developer", 4400);

    

    comp.AddEmployee(emp1);
    comp.AddEmployee(emp2);
    comp.AddEmployee(emp3);
    comp.AddEmployee(emp4);
    comp.AddEmployee(emp5);
    comp.AddEmployee(emp6);
    comp.AddEmployee(emp7);

    comp.Print();
    std::cout << "After remove " << std::endl;
    comp.RemoveEmployee("Kalin");
    comp.Print();

    return 0;
}