#include <iostream>

struct Student{

    int fn, course;
    double grade;

};

struct Group{

    Student *students;
    size_t size;
    double avgGrade;

};

Student InitStudent(const int &fn, const int &course, const double &grade){

    Student newStudent;

    newStudent.fn = fn;
    newStudent.course = course;
    newStudent.grade = grade;

    return newStudent;

}

void FindAverage(Group &myGroup){

    for(size_t i = 0; i < myGroup.size; ++i)
        myGroup.avgGrade += myGroup.students[i].grade;
    
    myGroup.avgGrade /= myGroup.size;

}

size_t FindMoreThanAvg(const Group &myGroup){

    size_t counter = 0;

    for(size_t i = 0; i < myGroup.size; ++i)
        counter += myGroup.students[i].grade >= myGroup.avgGrade;
    
    return counter;

}

int main(){

    Group myGroup;
    std::cin >> myGroup.size;
    myGroup.students = new(std::nothrow) Student[myGroup.size];

    if(!myGroup.students){

        std::cout << "Memory error\n";
        return -1;

    }

    int fn, course;
    double grade;

    for(size_t i = 0; i < myGroup.size; ++i){

        std::cin >> fn >> course >> grade;
        myGroup.students[i] = InitStudent(fn, course, grade);

    }
    
    std::cin >> grade;

    FindAverage(myGroup);

    std::cout << myGroup.avgGrade << ' ' << FindMoreThanAvg(myGroup) << '\n';

    delete[] myGroup.students;

    return 0;

}