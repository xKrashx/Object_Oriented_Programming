#include <iostream>

struct Student
{
	int facNum;
	int year;
	float grade;
};

// По условие ти се иска да се въвежда размер,
// защото целта е да се заделя динамична памет.
const int size = 100;

struct Group
{
	Student students[size];
	int count;
	float grade;

	void calculateGroupAvg()
	{
		float totalGrade = 0.0;
		for (int i = 0; i < count; i++)
		{
			totalGrade += students[i].grade;
		}
		grade = totalGrade / count;
	}

	int calculateRecipients(float minGrade)
	{
		int count = 0;
		for (int i = 0; i < this->count; i++)
		{
			if (students[i].grade >= minGrade)
			{
				count++;
			}
		}
		return count;
	}
};

// На теория можеш да си създадеш обекта и във функцията и направо да върнеш студента.
// Поне на мен ми изглежда по-логично, защото така се използва и конструктора, който се опитваме да имитираме.
void Studentt(Student& s, int facNum, int year, float grade)
{
	s.facNum = facNum;
	s.year = year;
	s.grade = grade;
}

void printStudent(const Student& s)
{
	std::cout << s.facNum << s.year << s.grade << std::endl;
}

int main()
{
	Group group;
	int n;
	std::cin >> n;
	if (n<1 || n>500)
	{
		std::cout << "Invalid input!" << std::endl;
		return 1;
	}

	group.count = n;

	for (int i = 0; i < n; i++)
	{
		int facNum, year;
		float grade;
		std::cin >> facNum >> year >> grade;
		if (facNum<10000 || facNum>100000 || year<1 ||
			year>4 || grade<2 || grade>6)
		{
			std::cout << "Invalid input!" << std::endl;
			return 1;
		}

		Studentt(group.students[i], facNum, year, grade);
	}

	float minGrade;
	std::cin >> minGrade;


	group.calculateGroupAvg();
	std::cout << group.grade << std::endl;

	int count = group.calculateRecipients(minGrade);
	std::cout << count << std::endl;

	return 0;
}
