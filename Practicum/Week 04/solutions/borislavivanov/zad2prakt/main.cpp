#include "student.hpp"
#include <iostream>
int main(){
    Student one;
    Student two;
    one.setName("Ivan Karanchev");
    one.setNumInClass(4);
    int temp [5] = {4,5,6,5,4};
    int temp2 [5] = {4,5,6,5,3};
    one.setSubjectsGrades(temp);
    two.setName("Petur Petkov");
    two.setNumInClass(6);
    two.setSubjectsGrades(temp2);
    one.Print();
    two.Print();
    std::cout<<two.compareAvarageGrades(one);
    return 0;
}