#include <iostream>

struct Student {
    int facultyNumber;
    int course;
    double averageGrade;
};

void initStudent(Student& student) {
    std::cin >> student.facultyNumber >> student.course >> student.averageGrade;
}

void printStudent(const Student& student) {
    std::cout << "FN: " << student.facultyNumber << ", Course: " << student.course
        << ", Avg Grade: " << student.averageGrade << std::endl;
}

struct Group {
    int studentCount;
    // Това трябва да е динамичен масив, чиито размер въвеждаме през конзолата.
    Student students[500]; // Maximum of 500 students
    double averageGroupGrade;
};

// Function to calculate the group's average grade
double calculateAverageGrade(const Group& group) {
    double total = 0;
    for (int i = 0; i < group.studentCount; i++) {
        total += group.students[i].averageGrade;
    }
    return total / group.studentCount;
}

int countScholarshipStudents(const Group& group, double minScholarshipGrade) {
    int count = 0;
    for (int i = 0; i < group.studentCount; i++) {
        if (group.students[i].averageGrade >= minScholarshipGrade) {
            count++;
        }
    }
    return count;
}

int main() {
    Group group;
    std::cin >> group.studentCount;

    for (int i = 0; i < group.studentCount; i++) {
        initStudent(group.students[i]);
    }

    group.averageGroupGrade = calculateAverageGrade(group);

    double minScholarshipGrade;
    std::cin >> minScholarshipGrade;

    int scholarshipCount = countScholarshipStudents(group, minScholarshipGrade);

    std::cout << group.averageGroupGrade << " " << scholarshipCount << std::endl;

    return 0;
}
