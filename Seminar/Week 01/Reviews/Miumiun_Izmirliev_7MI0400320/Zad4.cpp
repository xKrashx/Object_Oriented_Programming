#include <iostream>


struct Student {
	int fn;
	int kurs;
	double ocenka;
};

struct Grupa {
	Student* students;
	int count;
	double avgOcenka;
};

Student initStudent(int fn, int kurs, double ocenka) {
	Student st = {
		fn, kurs, ocenka
	};
	// Защо валидираш след като си направил обекта?!?
	// Би било логично създавайки обект, той да е валидно създаден с валидни данни.
	if (fn < 10000 || fn >= 100000) {
		std::cout << "FN must be >= 10000 and < 100000" << std::endl;

		st.fn = -1;
		return st;
	}
	if (kurs < 1 || kurs > 4) {
		std::cout << "Kurs must be >= 1 and <= 4" << std::endl;
		st.fn = -1;
		return st;
	}
	if (ocenka < 2 || ocenka > 6) {
		std::cout << "Ocenka must be >= 2 and <= 6" << std::endl;
		st.fn = -1;
		return st;
	}

	return st;
}

int getStudentsWithStipendiaCount(Student* students, int n, double minOcenka) {
	int count = 0;
	for (int i = 0; i < n;i++) {
		if (students[i].ocenka >= minOcenka) {
			count++;
		}
	}
	return count;
}

double getAVGUspeh(Student* students, int n) {
	double uspeh = 0;
	for (int i = 0; i < n; i++) {
		uspeh += students[i].ocenka;
	}
	return uspeh / n;
}

void printStudent(Student st) {
	std::cout << st.fn << " " << st.kurs << " " << st.ocenka << std::endl;
}

void printStudents(Student* students, int n) {
	for (int i = 0; i < n; i++) {
		printStudent(students[i]);
	}
}

int main() {
	int n;
	std::cin >> n;
	while (n < 1 || n>500) {
		std::cout << "Invalid input! \n n must be >= 1 and <= 500" << std::endl;
		std::cin >> n;
	}

	Grupa gr = {
		// Нямаш std::nothrow като аргумент на new, което може да доведе до crash.
		new Student[n], n, 0
	};

	

	
	for (int i = 0; i < n;i++) {
		int fn;
		int kurs;
		double ocenka;
		std::cin >> fn;
		std::cin >> kurs;
		std::cin >> ocenka;

		gr.students[i] = initStudent(fn,kurs,ocenka);
		
		if (gr.students[i].fn == -1) {
			delete[] gr.students;
			return -1;
		}


	}

	//printStudents(students, n);
	double minOcenka;
	std::cin >> minOcenka;

	int count = getStudentsWithStipendiaCount(gr.students, n, minOcenka);
	gr.avgOcenka = getAVGUspeh(gr.students, n);

	std::cout << gr.avgOcenka << " ";
	std::cout << count << std::endl;


	delete[] gr.students;
	return 0;
}