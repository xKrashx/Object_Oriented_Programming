// Идеално разписана задача
#include "task4.hpp"
#include <iostream>

namespace Task4 {
    float calculateGroupAverage(const Group& group) {
        if (group.studentCount == 0) return 0.0;

        float sum = 0.0;

        for (unsigned int i = 0; i < group.studentCount; i++) {
            sum += group.students[i].averageGrade;
        }

        return sum / group.studentCount;
    }

	unsigned int countScholarshipStudents(const Group& group, float minGrade) {
        unsigned int count = 0;

        for (unsigned int i = 0; i < group.studentCount; i++) {
            if (group.students[i].averageGrade >= minGrade) count++;
        }

        return count;
	}

    void initStudent(Student& s) {
        int course;

        do {
            std::cin >> s.facultyNumber >> course >> s.averageGrade;
        } while (course < FIRST || course > FOURTH ||
            s.averageGrade < GRADE_MIN || s.averageGrade > GRADE_MAX ||
            s.facultyNumber < FACULTY_NUMBER_MIN || s.facultyNumber > FACULTY_NUMBER_MAX);

        s.course = (Course)course;
    }

    int run() {
        Group g;
        std::cout << "Enter student count:" << "\n";

        do {
            std::cin >> g.studentCount;
        } while (g.studentCount < STUDENT_COUNT_MIN || g.studentCount > STUDENT_COUNT_MAX);

        g.students = new(std::nothrow) Student[g.studentCount];

        if (g.students == nullptr) {
            std::cout << "Memory allocation failed." << "\n";

            return 1;
        }

        std::cout << "Enter personal data for each student:" << "\n";

        for (unsigned int i = 0; i < g.studentCount; i++) {
            initStudent(g.students[i]);
        }

        float minGrade;
        std::cout << "Enter min scholarship grade:" << "\n";

        do {
            std::cin >> minGrade;
        } while (minGrade < GRADE_MIN || minGrade > GRADE_MAX);

        g.averageGrade = calculateGroupAverage(g);
        std::cout << g.averageGrade << countScholarshipStudents(g, minGrade);

        delete[] g.students;
        return 0;
    }
}