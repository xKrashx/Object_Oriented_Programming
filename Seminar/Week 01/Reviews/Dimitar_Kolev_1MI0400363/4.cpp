#include <iostream>

struct Student {
	int fn;
	int course;
	float grade;
};

std::istream &operator>>(std::istream &is, Student &o) {
	is >> o.fn >> o.course >> o.grade;
	return is;
}

std::ostream &operator<<(std::ostream &os, const Student &o) {
	os
		<< "FN: " << o.fn << std::endl
		<< "COURSE: " << o.course << std::endl
		<< "GRADE: " << o.grade;
	return os;
}

struct Group {
	Student *students;
	int n;
	float grade;

	int stipend(float m) {
		int x = 0;
		for(int i = 0; i < n; i++)
			x += students[i].grade > m;
		return x;
	}
};

int main() {
	int n;
	std::cin >> n;

	// Липсва валидация на n!
	// Не се подсигуряваме за коректен размер.

	// Липсва std::nothrow при заделянето на масив, което може да предизвика crash.
	// Другият вариант е да се обработи потенциалната грешка, но трябва да стигнем до там като материал.
	Group group = { new Student[n], n, 0 };
	for(int i = 0; i < n; i++) {
		std::cin >> group.students[i];
		group.grade += group.students[i].grade;
	}
	group.grade /= n;

	float m;
	std::cin >> m;

	std::cout << group.grade << " " << group.stipend(m) << std::endl;

	// Паметта, която си заделил не е освободена!!!
	// Това се счита отново за груба грешка и при две такива на контролно или изпит работата се анулира.

	return 0;
}

