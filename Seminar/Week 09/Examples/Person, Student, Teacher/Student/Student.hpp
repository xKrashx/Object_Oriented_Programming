#ifndef __STUDENT_HPP
#define __STUDENT_HPP

#include "../Person/Person.h"
#include <cstddef>

class Student : public Person{

public:
	Student() = default;
	Student(char const *name, unsigned age, size_t fn);
	
	size_t GetFn() const;
	void SetFn(size_t fn);

	// No need for big 4, since there is NO dyn. memory in Student
	// The compiler will generate valid:

	//Student(const Student& other);
	//Student& operator=(const Student& other); //no need 
	// ~Student()
	
	//See on the .cpp file how the compiler creates them

private:
	size_t fn = 0;

};

#endif