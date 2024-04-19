#include <iostream>

#include "Class.hpp"

int main()
{ 
    Student s1("Student 1", 1);
    s1.SetGrade(0, 5.00); s1.SetGrade(1, 6.00); s1.SetGrade(2, 5.25); s1.SetGrade(3, 4.00); s1.SetGrade(4, 5.50);

    Student s2("Student 2", 1);
    s2.SetGrade(0, 5.13); s2.SetGrade(1, 6.00); s2.SetGrade(2, 5.55); s2.SetGrade(3, 4.00); s2.SetGrade(4, 5.50);

    Student s3("Student 3", 1);
    s3.SetGrade(0, 5.86); s3.SetGrade(1, 6.00); s3.SetGrade(2, 6.00); s3.SetGrade(3, 5.00); s3.SetGrade(4, 4.50);
    
    Student s4("Student 4", 1);
    s4.SetGrade(0, 6.00); s4.SetGrade(1, 6.00); s4.SetGrade(2, 6.00); s4.SetGrade(3, 6.00); s4.SetGrade(4, 6.00);
    
    Student s5("Student 5", 1);
    s5.SetGrade(0, 5.76); s5.SetGrade(1, 6.00); s5.SetGrade(2, 5.25); s5.SetGrade(3, 4.25); s5.SetGrade(4, 5.50);
    
    Student s6("Student 6", 1);
    s6.SetGrade(0, 5.10); s6.SetGrade(1, 6.00); s6.SetGrade(2, 4.25); s6.SetGrade(3, 4.00); s6.SetGrade(4, 6.00);

    Class c1("5A");
    c1.AddStudent(s3);
    c1.AddStudent(s1);
    c1.AddStudent(s5);
    c1.DisplayInformation();
    std::cout << "average store: " << c1.AverageScore() << std::endl;

    std::cout << "----------------------------------------------" << std::endl;

    Class c2("5B");
    c2.AddStudent(s4);
    c2.AddStudent(s6);
    c2.AddStudent(s2);
    c2.DisplayInformation();
    std::cout << "average store: " << c2.AverageScore() << std::endl;

    std::cout << "----------------------------------------------" << std::endl;

    switch(c1.CompareScores(c2))
    {
        case -1: 
            std::cout << c1.GetName() << " has a lower average score than " << c2.GetName() << std::endl;
            break;

        case 0: 
            std::cout << c1.GetName() << " has the same average score as " << c2.GetName() << std::endl;
            break;

        case 1: 
            std::cout << c1.GetName() << " has a higher average score than " << c2.GetName() << std::endl;
            break;
    }

    return 0;
}
