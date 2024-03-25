#include "Student.hpp"

Student::Student(const char *new_name)
{
    strcpy(this->name, new_name);
};

void Student::SetNumber(unsigned int number)
{
    this->number = number;
};

unsigned int Student::GetNumber()
{
    return this->number;
};

char *Student::GetName()
{
    return this->name;
}

void Student::SetGrade(Grade grade)
{
    bool added = false;

    if (grade.mark < 2 || grade.mark > 6)
    {
        std::cout << "Mark must be between 2 and 6!" << std::endl;
        return;
    }

    for (size_t i = 0; i < NUM_OF_SUBJECTS; i++)
    {
        if (!strcmp(grade.Subject, this->grades[i].Subject))
        {
            this->grades[i].mark = grade.mark;
            // std::cout << "Grade added!" << std::endl;
            added = true;
            break;
        }
    }
    if (!added)
    {
        std::cout << "No such subject!" << std::endl;
    }
};

double Student::GetGrade(char *subject)
{
    bool found = false;
    for (size_t i = 0; i < NUM_OF_SUBJECTS; i++)
    {
        if (!strcmp(subject, this->grades[i].Subject))
        {
            return this->grades[i].mark;
        }
    }

    if (!found)
    {
        std::cout << "No such subject" << std::endl;
    }
}

void Student::PrintAllGrades()
{
    for (size_t i = 0; i < NUM_OF_SUBJECTS; i++)
    {
        if (this->grades[i].mark < 3)
        {
            std::cout << this->grades[i].Subject << ':' << '2' << std::endl;
            continue;
        }
        else
            std::cout << this->grades[i].Subject << ':' << this->grades[i].mark << std::endl;
    }
};

double Student::GetAverageGrade()
{
    double sum_of_all = 0;
    for (size_t i = 0; i < NUM_OF_SUBJECTS; i++)
    {
        if (this->grades[i].mark < 3)
        {
            sum_of_all += 2;
        }
        else
            sum_of_all += this->grades[i].mark;
    }

    return sum_of_all / NUM_OF_SUBJECTS;
}

bool Student::operator==(Student &student)
{
    if (!strcmp(this->name, student.name)){
        return 1;
    }
    return 0;
};