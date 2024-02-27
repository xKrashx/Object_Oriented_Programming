#include <iostream>
#include <fstream>
#include <cstring>

struct Student{

	char name[24];
	int age;
	int fn;

};

void ReadStudent(Student &student, std::ifstream &f){

    size_t nameLen;

    f.read((char *)&nameLen, sizeof(size_t)); // First we read the size of the name!

    f.read(student.name, nameLen);
    student.name[nameLen] = '\0';

    f.read((char *)&student.fn, sizeof(int));
    f.read((char *)&student.age, sizeof(int));
    f.read((char *)&student.fn, sizeof(double));

}

Student *ReadFromFile(size_t &studentsCount, std::ifstream &f){

	size_t numberOfStudents;
	f.seekg(0, std::ios::beg);
	f.read((char *)&numberOfStudents, sizeof(size_t));

	Student *ptr = new(std::nothrow) Student[studentsCount];
	if(!ptr) return nullptr;

	for(size_t i = 0; i < numberOfStudents; ++i) ReadStudent(ptr[i], f);

	return ptr;

}


int main(){

	std::ifstream file("students.dat", std::ios::binary);
			
	if(!file.is_open()){

		std::cout << "Error while opening the file!\n";
		return -1;

	}

	size_t count;
	Student *students = ReadFromFile(count, file);

	if(!students){

		std::cout << "Memory error\n";
		file.close();
		return -1;

	}

	for(size_t i = 0; i < count; i++)
		std::cout << "Name: " << students[i].name << ", age: " << students[i].age << ", fn: " << students[i].fn << '\n';

	delete[] students;
	file.close();

	return 0;

}
