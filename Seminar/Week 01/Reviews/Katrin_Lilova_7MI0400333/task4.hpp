#pragma once

namespace Task4 {
	const unsigned int STUDENT_COUNT_MAX = 500;
	const unsigned int STUDENT_COUNT_MIN = 1;

	const unsigned int FACULTY_NUMBER_MAX = 99999;
	const unsigned int FACULTY_NUMBER_MIN = 10000;

	const float GRADE_MAX = 6.0;
	const float GRADE_MIN = 2.0;

	enum Course {
		FIRST = 1,
		SECOND,
		THIRD,
		FOURTH
	};

	struct Student {
		unsigned int facultyNumber;
		Course course;
		float averageGrade;
	};

	struct Group {
		float averageGrade;
		unsigned int studentCount;
		Student* students;
	};

	int run();

	float calculateGroupAverage(const Group& group);
	unsigned int countScholarshipStudents(const Group& group, float minGrade);
	void initStudent(Student& s);
}