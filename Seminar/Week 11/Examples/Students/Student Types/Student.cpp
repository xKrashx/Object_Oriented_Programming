#include "Student.hpp"
#include <stdexcept>
#include <cstring>
#include <utility>
#include <iostream>

size_t Student::numberOfStudentsCreated = 0;

Student::Student(char const *name, size_t fn){

    if(!name) throw std::invalid_argument("Name must not be a nullptr");
    if(9'999 >= fn || fn >= 100'000) throw std::invalid_argument("Fn is not in the correct format");

    m_Name = new char[strlen(name) + 1];
    strcpy(m_Name, name);
    m_Fn = fn;
    ++numberOfStudentsCreated;

}

Student::Student(Student const &other){
    Copy(other);
}

Student::Student(Student &&other) noexcept{
    Move(std::move(other));
}

Student::~Student() noexcept{
    // Unalive student
    --numberOfStudentsCreated;
    Free();
}

Student &Student::operator =(Student const &other){

    if(this == &other) return *this;

    char *newName = new char[strlen(m_Name) + 1];
    strcpy(newName, other.m_Name);
    Free();
    m_Name = newName;
    strcpy(m_Name, newName);
    m_Fn = other.m_Fn;

    return *this;

}

Student &Student::operator =(Student &&other) noexcept{
    
    if(this == &other) return *this;

    Free();
    Move(std::move(other));

    return *this;

}

char const *Student::GetName() const{
    return m_Name;
}

size_t Student::GetFN() const{
    return m_Fn;
}

size_t Student::AliveStudents(){
    return numberOfStudentsCreated;
}

void Student::Copy(Student const &other){

    m_Name = new char[strlen(other.m_Name) + 1];
    strcpy(m_Name, other.m_Name);
    m_Fn = other.m_Fn;

}

void Student::Move(Student &&other) noexcept{

    m_Name = std::exchange(other.m_Name, nullptr);
    m_Fn = other.m_Fn;

}

void Student::Free() noexcept{
    delete m_Name;
}