#include <iostream>

struct UniStudent
{
	// Защо да трябва да е масив?
	// Защо да заемаме 20 байта, като можем да съберем 5 цифрено число в 2(unsigned short)?
	// Това 10х разхищение на памет може много бързо да ескалира в големи проекти.
	// Плюс това става още по-сложно да се управляват 5 клетки вместо 1 единствено число.
	int facultyNumber; //it should be int facultyNumber[5] but there was a problem with reading it as an array
	int course;
	double averageGrade;
};


// const UniStudent* students!!!!!!
// Като няма да променяш даден обект във функцията го подаваш като константа!
// Идеята на една функция е да прави едно нещо.
// Тази функция смята средната оценка на групата студенти и едновременно
// смята колко студенти трябва да получат стипендия.
unsigned checkHowManyStudentsAreRewarded(UniStudent* students, unsigned n, double minimalGradeRequired, double& avGrade)
{
	unsigned rewardedStudents = 0;

	for (unsigned i = 0; i < n; i++)
	{
		avGrade += students[i].averageGrade;

		if (students[i].averageGrade >= minimalGradeRequired)
		{
			rewardedStudents++;
		}
	}

	avGrade = avGrade / n;
	return rewardedStudents;
}

int main() {

	std::cout << "Please enter the number of students: ";
	unsigned n;

	std::cin >> n;
	if (n < 1 || n > 500)
	{
		std::cout << "Invalid input!";
		return 1;
	}

	// Няма std::nothrow като параметър на new, което може да предизвика crash.
	UniStudent* students = new UniStudent[n];

	std::cout << "Please enter the faculty numbers of students, their course and their grade: ";

	for (unsigned i = 0; i < n; i++)
	{
		std::cin >> students[i].facultyNumber >> students[i].course >> students[i].averageGrade;

		if (students[i].facultyNumber < 10000 || students[i].facultyNumber >= 100000) {
			std::cout << "Invalid faculty number!";
			delete[] students;
			return 1;
		}


		
		if (students[i].course < 1 || students[i].course > 4)
		{
			std::cout << "Invalid course!";
			// Не освобождаваме паметта!
			return 1;
		}

		
		if (students[i].averageGrade < 2 || students[i].averageGrade > 6)
		{
			std::cout << "Invalid grade!";
			// Не освобождаваме паметта!
			return 1;
		}
	}

	double minimalGradeRequired;
	std::cin >> minimalGradeRequired;
	if (minimalGradeRequired < 2 || minimalGradeRequired > 6)
	{
		std::cout << "Invalid grade!";
		// Не освобождаваме паметта!
		return 1;
	}

	double avGrade = 0;
	unsigned rewardedStudents = checkHowManyStudentsAreRewarded(students, n, minimalGradeRequired, avGrade);

	std::cout << "The average score of the group is: " << avGrade << std::endl;
	std::cout << "The rewarded students are: " << rewardedStudents << std::endl;

	delete[] students;
	return 0;
}