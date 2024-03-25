#include <iostream>
#include "Student.hpp"
#include "Classroom.hpp"

int main()
{
    Student a("stoqn");
    Student w("asdasd");
    Student b("dascz");
    Student c("poiuz");


    a.SetGrade({"Math", 6});
    a.SetGrade({"English", 6});
    a.SetGrade({"PE", 6});
    a.SetGrade({"Literature", 6});
    a.SetGrade({"Geometry", 6});
    
    w.SetGrade({"Math", 6});
    w.SetGrade({"English", 6});
    w.SetGrade({"PE", 6});
    w.SetGrade({"Literature", 6});
    w.SetGrade({"Geometry", 6});

    Classroom clas, clas1;
    clas.AddStudent(a);
    clas.AddStudent(w);
    clas.AddStudent(b);
    clas.AddStudent(c);

    clas1.AddStudent(b);
    clas1.AddStudent(c);

    std::cout <<std::boolalpha <<clas.CompareAverages(clas1) << std::endl;
    std::cout << std::endl;
    
    clas.PrintStudents();
    std::cout << std::endl;
    clas1.PrintStudents();

    

    return 0;
}