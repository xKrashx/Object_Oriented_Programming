#include "student.hpp"
#include <iostream>
#include <cstring>

void Student::InputStudent(){
    std::cin.getline(this->name,nameLenght);
    std::cin>>this->numInClass;
    for(size_t i=0;i<numGrades;i++)std::cin>>this->subjectsGrades[i];
}
void Student::OutputStudent() const{
    std::cout<<this->name<<std::endl;
    std::cout<<this->numInClass<<std::endl;
    for(size_t i = 0;i<numGrades;i++){
        std::cout<<this->subjectsGrades[i]<<' ';
    }
    std::cout<<std::endl;
}
double Student::AvarageGrade() const{
    double temp = 0;
    for(size_t i=0;i<numGrades;i++){
        temp += this->subjectsGrades[i];
    }
    return temp/numGrades;
}
const char* Student::getName() const{
    return this->name;
}
size_t Student::getNumInClass() const{
    return this->numInClass;
}
const double* Student::getSubjectGrades(size_t i) const{
   return this->subjectsGrades;
}
void Student::setName(const char* Name){
    strcpy(this->name,Name);
}
void Student::setNumInClass(size_t num){
    this->numInClass = num;
}
void Student::setSubjectsGrades(int grades[]){
    for(size_t i =0;i<numGrades;i++){
        this->subjectsGrades[i] = grades[i];
    }
}
bool Student::compareAvarageGrades(Student &other)const{
    if(this->AvarageGrade()>other.AvarageGrade())return true;
    return false;
}

void Student::Print() const{
      std::cout<<this->name<<' '<<this->numInClass<<' ';
      for(size_t i = 0;i<numGrades;i++)
        std::cout<<this->subjectsGrades[i]<<' ';
    std::cout<<std::endl;
    std::cout<<"avrgd grade"<<' '<<this->AvarageGrade();
    std::cout<<std::endl;
    
}