#include <iostream>

#include "Student.hpp"

int main()
{
    Student s1("Student 1", 9);
    s1.SetGrade(0, 5.00);
    s1.SetGrade(1, 6.00);
    s1.SetGrade(2, 5.25);
    s1.SetGrade(3, 4.00);
    s1.SetGrade(4, 5.50);
    s1.Print();

    Student s2;
    s2.Read();
    s2.Print();

    switch(s1.Compare(s2))
    {
        case -1: 
            std::cout << s1.GetName() << " has a lower average grade than " << s2.GetName() << std::endl;
            break;

        case 0: 
            std::cout << s1.GetName() << " has the same average grade as " << s2.GetName() << std::endl;
            break;

        case 1: 
            std::cout << s1.GetName() << " has a higher average grade than " << s2.GetName() << std::endl;
            break;
    }

    return 0;
}
