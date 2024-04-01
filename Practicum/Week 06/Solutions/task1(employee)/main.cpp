#include "employee.h"

int main()
{
    Employee b("Ivan", "developer", 3546.53); ;
    Employee a("Ivan", "developer", 3546.53);
    a.Print();
    
    a.SetEmployeeName("georgi");
    a.SetEmployeePosition("CEO");
    a.SetEmployeeSalary(687.5);

    a.Print();
    a = b;
    a.Print();

    return 0;
}