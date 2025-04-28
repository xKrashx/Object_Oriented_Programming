#ifndef __TEACHER_HPP
#define __TEACHER_HPP

#include "../Person/Person.h"
#include <cstddef>

class Teacher : public Person{

public:
	Teacher(char const *name, unsigned age, char const * const *subjects, size_t subjectsCount);
	Teacher(Teacher const &other);
	Teacher(Teacher &&other);
	~Teacher();

	Teacher &operator =(Teacher const &other);
	Teacher &operator =(Teacher &&other);

private:
	void Copy(Teacher const &other);	// само нещата, които са от Teacher
	void Move(Teacher &&other);			// само нещата, които са от Teacher
	void Free(size_t subjectsCount);

	char **m_Subjects;
	size_t m_SubjectsCount;

};

#endif