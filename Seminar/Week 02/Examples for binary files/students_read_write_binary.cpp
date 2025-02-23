#include <iostream>
#include <fstream>
#include <cstring>

struct Student{

    char name[24];
    int fn;
    int gradesCount;
    double averageGrade;

};

void Print(Student const &st){

    std::cout << st.name << " "
        << st.fn << " "
        << st.gradesCount << " "
        << st.averageGrade << '\n';

}

Student CreateStudent(char const *name, int const fn, int const gradesCount, double const avGrade){

    Student obj;

    strcpy(obj.name, name);
    obj.fn = fn;
    obj.gradesCount = gradesCount;
    obj.averageGrade = avGrade;

    return obj;

}

void SaveStudentToFile(std::ofstream &f, Student const &st){

    size_t nameLen = strlen(st.name);

    f.write((char const *)&nameLen, sizeof(size_t));  // First we write the size of the name!
    f.write(st.name, nameLen);

    f.write((char const *)&st.fn, sizeof(int));
    f.write((char const *)&st.gradesCount, sizeof(int));
    f.write((char const *)&st.averageGrade, sizeof(double));

}

Student ReadStudentFromFile(std::ifstream &f){

    Student res;

    size_t nameLen;

    f.read((char *)&nameLen, sizeof(size_t)); // First we read the size of the name!

    f.read(res.name, nameLen);
    res.name[nameLen] = '\0';

    f.read((char *)&res.fn, sizeof(int));
    f.read((char *)&res.gradesCount, sizeof(int));
    f.read((char *)&res.averageGrade, sizeof(double));

    return res;

}

int main(){

    {   // save students to file

        Student s1 = CreateStudent("Ivan", 1234, 2, 4);
        Student s2 = CreateStudent("Petur", 5555, 5, 5.5);

        std::ofstream f1("uni.dat", std::ios::binary | std::ios::trunc);

        if(!f1.is_open()){

            std::cout << "Error\n";
            return -1;

        }

        SaveStudentToFile(f1, s1);
        SaveStudentToFile(f1, s2);

        f1.close();

    }

    {   // read students from file

        std::ifstream f2("uni.dat", std::ios::binary);

        if(!f2.is_open()){

            std::cout << "Error\n";
            return -1;

        }

        Student s1 = ReadStudentFromFile(f2);
        Student s2 = ReadStudentFromFile(f2);

        Print(s1);
        Print(s2);

        f2.close();

    }

    return 0;

}