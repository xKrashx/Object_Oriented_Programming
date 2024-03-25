#include "Classroom.hpp"
#include "Student.hpp"

Classroom::Classroom()
{
    students = new (std::nothrow) Student[1];
};

void Classroom::AddStudent(Student &student)
{

    if (taken_places == NUM_OF_STUDENTS)
    {
        std::cout << "No space in this class!" << std::endl;
        return;
    }

    if (!strcmp(student.GetName(), ""))
    {
        std::cout << "Student must have a name!" << std::endl;
        return;
    }

    Student *new_students = new (std::nothrow) Student[taken_places+1];
    for (size_t i = 0; i < taken_places+1; i++)
    {
        new_students[i] = this->students[i];
    }

    delete[] this->students; 
    this->students = new_students;
    
    this->students[taken_places] = student;
    this->students[taken_places].SetNumber(taken_places + 1);
    std::cout << "Added " << students[taken_places].GetName() << std::endl;
    taken_places++;
};

void Classroom::PrintStudents()
{
    for (size_t i = 0; i < taken_places; i++)
    {
            std::cout << this->students[i].GetNumber() << ':' << this->students[i].GetName() << std::endl;
    }
};

unsigned int Classroom::GetStudentNumber(Student &student)
{
    for (size_t i = 0; i < NUM_OF_STUDENTS; i++)
    {
        if (student == this->students[i])
        {
            return this->students[i].GetNumber();
        }
    }
    return 0;
};
 
Student Classroom::GetStudentByNumber(unsigned int number)
{
    for (size_t i = 0; i < NUM_OF_STUDENTS; i++)
    {
        if (this->students[i].GetNumber() == number)
            return this->students[i];
    }

    std::cout << "No student with this number." << std::endl;
    return 0;
}

double Classroom::GetAverageClassGrade()
{
    double sum = 0;
    for (size_t i = 0; i < taken_places; i++)
    {
        sum += this->students[i].GetAverageGrade();
    }

    return sum/taken_places;
    
};

bool Classroom::CompareAverages(Classroom &other){
    if (this->GetAverageClassGrade() > other.GetAverageClassGrade()) return 1;
    return 0;
};
