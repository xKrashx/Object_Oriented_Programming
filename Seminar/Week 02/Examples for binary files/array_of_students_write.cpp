#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

struct Student{

	char name[24];
	int age;
	int fn;

};

void InitStudent(Student& st, char const *name, int const age, int const fn){

	strcpy(st.name, name);
	st.age = age;
	st.fn = fn;

}

void SaveToFile(Student const *students, size_t const count, std::ofstream &file){

	file.write((char const *)&count, sizeof(size_t));

	for(size_t i = 0; i < count; ++i){

		size_t nameSize = strlen(students[i].name);
		file.write((char const *)&nameSize, sizeof(size_t));
		file.write(students[i].name, nameSize);
		file.write((char const *)&students[i].age, sizeof(int));
		file.write((char const *)&students[i].fn, sizeof(int));

	}

}


int main(){

	size_t const STUDENTS_SIZE = 4;

	Student* students = new(std::nothrow) Student[STUDENTS_SIZE];
	if(!students){

		std::cout << "Memory error\n";
		return -1;

	}

	InitStudent(students[0], "ivan", 44, 1234);
	InitStudent(students[1], "petur", 12, 765);
	InitStudent(students[2], "alex", 15, 44);
	InitStudent(students[3], "katerina", 19, 12134);

	std::ofstream file("students.dat", std::ios::binary | std::ios::trunc);

	if(!file.is_open()){

		std::cout << "Error while opening the file!\n";
		delete[] students;
		return -1;

	}

	SaveToFile(students, STUDENTS_SIZE, file);

	delete[] students;
	file.close();

	return 0;

}
