#include <iostream>
#include "class.hpp"
#include "student.hpp"

size_t Class::getCurrNumINClass() const{
    return this->currentStudInClass;
}

void Class::PrintClass() const{
    for(size_t i =0;i<this->currentStudInClass;i++)
        this->clas[i].Print();
}
Student Class::FindStudent(size_t numInClass) const{
     
    for(size_t i =0;i<this->currentStudInClass;i++){
        if(this->clas[i].getNumInClass() == numInClass)
        return this->clas[i];
    }
    throw std::invalid_argument("student NOT found");
}
bool Class::StudentInClass(size_t numInClass)const{
    for(size_t i =0;i<this->currentStudInClass;i++){
        if(this->clas[i].getNumInClass() == numInClass)
        return true;
    }
    return false;
}
void Class::addStudent(Student &student){
    if(!(this->StudentInClass(student.getNumInClass()))){
    this->clas[this->currentStudInClass] = student;
    this->currentStudInClass+=1;
    }
    else throw std::invalid_argument("student IN class");
}
void Class::removeStudent(size_t numInClass){
    for(size_t i =0;i<this->currentStudInClass;i++){
        if(this->clas[i].getNumInClass() == numInClass)
        {
            for(size_t j = i;j<currentStudInClass-1;j++)
            this->clas[j] = this->clas[j+1];
        }
        this->currentStudInClass-=1;
        break;
    }
}
double Class::AvarageGradeInClass() const{
    double temp = 0;
    for(size_t i =0;i<this->currentStudInClass;i++){
        temp+= this->clas[i].AvarageGrade();
    }
    temp/=this->currentStudInClass;
    return temp;
}
bool Class::CompareAVGRadesInClasses(Class &other) const{
    if(this->AvarageGradeInClass()>other.AvarageGradeInClass())return true;
    return false;
}
