#include <iostream>
#include <cmath>

struct Student {
	int fn;
	int course;
	double grade;

	void print() {
		std::cout << fn << " " << course << " " << grade << std::endl;
	}
};

Student initStudent(int fn, int course, double grade) {
	Student newStudent;
	newStudent.fn = fn;
	newStudent.course = course;
	newStudent.grade = grade;
	return newStudent;
}

struct Group {
	int size;
	// Тук трябва да се използва динамична памет отново.
	// Защо иначе да се въвежда размер, ако ще е един и същ всеки път.
	Student students[100];
	double avgGrade;
};

// Слагай константи на обекти, които няма да променяш във функцията!
double calculateAverageGrade(Group& group) {
	double sum = 0;
	for (int i = 0; i < group.size; i++) {
		sum += group.students[i].grade;
	}
	return sum / group.size;
}

// Същата забележка тук. Константа!
int countScholarshipStudents(Group& group, double minGrade) {
	int count = 0;
	for (int i = 0; i < group.size; i++) {
		if (group.students[i].grade >= minGrade) {
			count++;
		}
	}
	return count;
}


int main() {
	int n;
	std::cin >> n;

	// Никаква валидация за n!!!
	// Какво става ако въведа отрицателна стойност.

	Group group;
	group.size = n;

	for (int i = 0; i < n; i++) {
		int fn, course;
		double grade;
		std::cin >> fn;
		while (fn < 10000 || fn >= 100000) {
			std::cout << "Invalid faculty number! (10000 <= fn < 100000): ";
			std::cin >> fn;
		}
		std::cin >> course;
		while (course < 1 || course > 4) {
			std::cout << "Invalid course! (1 <= course <= 4): ";
			std::cin >> course;
		}
		std::cin >> grade;
		while (grade < 2.0 || grade > 6.0) { 
			std::cout << "Invalid grade! (2 <= grade <= 6): ";
			std::cin >> grade;
		}
		group.students[i] = initStudent(fn, course, grade);

	}

	double minScholarshipGrade;
	std::cin >> minScholarshipGrade;

	group.avgGrade = calculateAverageGrade(group);
	int scholarshipCount = countScholarshipStudents(group, minScholarshipGrade);

	std::cout << group.avgGrade << " " << scholarshipCount << std::endl;

	return 0;
}