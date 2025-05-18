#include "Major.hpp"
#include <stdexcept>
#include <iostream>
#include <utility>
#include <random>
#include <ctime>

Major::Major(){
    m_Students = new Student *[m_Capacity];
}

Major::Major(Major const &other){
    Copy(other);
}

Major::Major(Major &&other){
    Move(std::move(other));
}

Major::~Major(){
    Free();
}

Major &Major::operator =(Major const &other){

    if(this == &other) return *this;

    *this = Major(other);

    return *this;

}

Major &Major::operator =(Major &&other){

    if(this == &other) return *this;

    Free();
    Move(std::move(other));

    return *this;

}

void Major::AddStudent(Student *student){

    if(m_Size == m_Capacity) Resize(m_Capacity *= 2);
    m_Students[m_Size++] = student -> Clone();

}

void Major::YeetFromUni(size_t index){

    if(index >= m_Size) throw std::out_of_range("Index out of range");
    delete m_Students[index];
    m_Students[index] = nullptr;
    if(m_Size == m_Capacity / 4) Resize(m_Capacity /= 2);

}

void Major::SwapMajor(size_t index, Major &other){

    if(index >= m_Size) throw std::out_of_range("Index out of range");
    other.AddStudent(m_Students[index]);
    YeetFromUni(index);

}

size_t Major::Size() const{
    return m_Size;
}

size_t Major::TakeExam() const{

    size_t studentsThatHavePassed = 0;
    std::knuth_b rand_engine(time(nullptr));  // replace knuth_b with one of the engines listed below
    std::uniform_real_distribution<> uniform_zero_to_one(0.0, 1.0);

    for(size_t i = 0; i < m_Size; ++i)
        if(uniform_zero_to_one(rand_engine) <= m_Students[i] -> PercentageToPassTheExam()){

            std::cout << m_Students[i] -> GetName() << " was given the chance to live a happy live\n";
            ++studentsThatHavePassed;

        }

    return studentsThatHavePassed;

}

Student *&Major::operator [](size_t index){

    if(index >= m_Size) throw std::out_of_range("Index out of range");
    return m_Students[index];

}
Student const *Major::operator [](size_t index) const{
    
    if(index >= m_Size) throw std::out_of_range("Index out of range");
    return m_Students[index];

}

bool Major::IsAdequateMajor() const{
    return TakeExam() * 2 >= m_Size;
}

void Major::Resize(size_t newCapacity){

    Student **newArray = new Student *[newCapacity];
    for(size_t i = 0; i < m_Size; ++i)
        newArray[i] = m_Students[i] -> Clone();
    Free();
    m_Students = newArray;

}

void Major::Copy(Major const &other){

    m_Students = new Student *[other.m_Capacity];
    m_Capacity = other.m_Capacity;
    m_Size = other.m_Size;
    for(size_t i = 0; i < other.m_Size; ++i)
        if(other.m_Students[i]) m_Students[i] = other.m_Students[i] -> Clone();
        else m_Students[i] = nullptr;

}

void Major::Move(Major &&other){

    m_Students = std::exchange(other.m_Students, nullptr);
    m_Capacity = other.m_Capacity;
    m_Size = other.m_Size;

}

void Major::Free(){
    
    for(size_t i = 0; i < m_Size; ++i)
        delete m_Students[i];
    delete[] m_Students;

}