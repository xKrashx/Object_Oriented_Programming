#include "Teacher.hpp"
#include <stdexcept>
#include <cstring>
#include <utility>
#include <new>

Teacher::Teacher(char const *name, unsigned age, char const * const *subjects, size_t subjectsCount): Person(name, age){

	this -> m_Subjects = new char *[subjectsCount];

	for (size_t i = 0; i < subjectsCount; i++){

		this -> m_Subjects[i] = new(std::nothrow) char[strlen(subjects[i]) + 1];

		if(!this -> m_Subjects[i]){

			Free(i);
			throw std::bad_alloc();

		}

		strcpy(this -> m_Subjects[i], subjects[i]);

	}

	this -> m_SubjectsCount = subjectsCount;

}

Teacher::Teacher(Teacher const &other): Person(other){
	Copy(other); //only the teacher stuff is copied
}

Teacher::Teacher(Teacher &&other): Person(other){
	Move(std::move(other)); //only the teacher stuff is copied
}

Teacher& Teacher::operator=(const Teacher& other){

	if (this == &other) return *this;

	*this = Teacher(other);

	return *this;

}

Teacher& Teacher::operator=(Teacher &&other){

	if (this == &other) return *this;

	Person::operator=(other); //delete data of person + copy the data from person
	Free(m_SubjectsCount);
	Move(std::move(other));

	return *this;

}

Teacher::~Teacher(){
	Free(m_SubjectsCount);
} // destr person

void Teacher::Copy(Teacher const &other){

	m_Subjects = new char* [other.m_SubjectsCount];
	
	for (size_t i = 0; i < other.m_SubjectsCount; i++)
	{
		m_Subjects[i] = new char[strlen(other.m_Subjects[i]) + 1];
		strcpy(m_Subjects[i], other.m_Subjects[i]);
	}

	m_SubjectsCount = other.m_SubjectsCount;
}

void Teacher::Move(Teacher &&other){

	m_Subjects = std::exchange(other.m_Subjects, nullptr);
	m_SubjectsCount = other.m_SubjectsCount;

}

void Teacher::Free(size_t subjectsCount){

	for(size_t i = 0; i < subjectsCount; i++)
		delete[] m_Subjects[i];
	delete[] m_Subjects;

}