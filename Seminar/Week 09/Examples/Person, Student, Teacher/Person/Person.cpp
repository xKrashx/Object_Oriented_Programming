#include "Person.hpp"
#include <iostream>
#include <cstring>
#include <utility>

Person::Person(char const *m_Name, int m_Age){

	SetName(m_Name);
	SetAge(m_Age);

}

Person::Person(Person const &other){
	Copy(other);
}

Person::Person(Person &&other){
	Move(std::move(other));
}

Person& Person::operator=(const Person& other){

	if (this == &other) return *this;

	*this = Person(other);

	return *this;

}

Person& Person::operator=(Person &&other){

	if (this == &other) return *this;

	Free();
	Move(std::move(other));

	return *this;

}

char const *Person::GetName() const{
	return m_Name;
}

int Person::GetAge() const{
	return m_Age;
}

void Person::SetName(char const *name){

	if(!m_Name || this -> m_Name == name) return;
	
	size_t const NAME_LENGTH = strlen(name);
	char *temp = new char[NAME_LENGTH + 1];
	strcpy(temp, name);

	delete[] this -> m_Name;
	this -> m_Name = temp;

}

void Person::SetAge(unsigned m_Age){
	this->m_Age = m_Age;
}


Person::~Person(){
	Free();
}

void Person::Print() const{
	std::cout << m_Name << " " << m_Age << '\n';
}


void Person::Copy(Person const &other){

	m_Name = new char[strlen(other.m_Name) + 1];
	strcpy(m_Name, other.m_Name);
	m_Age = other.m_Age;

}

void Person::Move(Person &&other){

	m_Name = std::exchange(other.m_Name, nullptr);
	m_Age = other.m_Age;

}

void Person::Free(){
	delete[] m_Name;
}