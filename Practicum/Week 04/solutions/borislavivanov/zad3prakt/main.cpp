#include <iostream>
#include "student.hpp"
#include "class.hpp"

int main(){
    Class a;
    Class b;

    Student three;
    Student four;

    int temp3 [5] = {3,5,6,3,4};
    int temp4 [5] = {4,3,6,5,5};
    three.setName("Sasho Roman");
    three.setNumInClass(4);
    three.setSubjectsGrades(temp3);
    four.setName("Daniel Kornev");
    four.setNumInClass(6);
    four.setSubjectsGrades(temp4);

    Student one;
    Student two;

    one.setName("Ivan Karanchev");
    one.setNumInClass(3);
    int temp [5] = {4,5,6,5,4};
    int temp2 [5] = {4,5,6,5,3};
    one.setSubjectsGrades(temp);
    two.setName("Petur Petkov");
    two.setNumInClass(6);
    two.setSubjectsGrades(temp2);
    
    

    a.addStudent(one);
    a.addStudent(two);
    std::cout<<std::endl;
    a.PrintClass();
    std::cout<<std::endl;
    //a.addStudent(one);
    a.removeStudent(one.getNumInClass());
    std::cout<<std::endl;
    a.PrintClass();
    std::cout<<std::endl;
    b.addStudent(four);
    b.addStudent(three);
    std::cout<<"avrg Grade In Class "<<b.AvarageGradeInClass()<<std::endl;
    std::cout<<std::boolalpha<<"Is avrg garde of a higher than b : "<<a.CompareAVGRadesInClasses(b)<<std::endl;
    std::cout<<"student found: ";
    a.FindStudent(6).Print();
    std::cout<<std::endl;
    b.PrintClass();

    return 0;
}