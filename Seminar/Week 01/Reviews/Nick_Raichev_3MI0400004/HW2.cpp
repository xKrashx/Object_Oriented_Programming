// Това не е втора задача!
#include <iostream>

struct Student {
    int facultyNumber;
    int course;
    double averageGrade;
};

// Function to initialize a student with valid input
void initStudent(Student& student) {
    std::cin >> student.facultyNumber >> student.course >> student.averageGrade;
}

// Function to print a student's details (not required in the output but useful for debugging)
void printStudent(const Student& student) {
    std::cout << "FN: " << student.facultyNumber << ", Course: " << student.course
        << ", Avg Grade: " << student.averageGrade << std::endl;
}

struct Group {
    int studentCount;
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

// Function to count how many students qualify for a scholarship
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

    // Read all students
    for (int i = 0; i < group.studentCount; i++) {
        initStudent(group.students[i]);
    }

    // Calculate the average grade of the group
    group.averageGroupGrade = calculateAverageGrade(group);

    // Read the minimum grade for a scholarship
    double minScholarshipGrade;
    std::cin >> minScholarshipGrade;

    // Count students eligible for a scholarship
    int scholarshipCount = countScholarshipStudents(group, minScholarshipGrade);

    // Print the results
    std::cout << group.averageGroupGrade << " " << scholarshipCount << std::endl;

    return 0;
}
