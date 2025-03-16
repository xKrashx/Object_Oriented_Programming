// Идеално разписана задача.
#include <iostream>


/*
������ 4: �������� ��������� �������� �������. ����� ������� �� �������� ���� ���������� �����, ���� � ������ ������ �� �����.
����� ������� � � �����, �����, ����� ��� �������� ����. ������������ ������ ������ �� ���������� ���� �����. �������� ��������� ��������������� ������� initStudent(...);,
����� ������� �������� ����� �� �������. �� �� ������ �������, ����� �������� �������.

�������� ��������� �������� �����. ���� ����� �� ������ �� N �� ���� ��������. ����������� ���� ���� ������ �� ���� ������� ����� �� �������. 
�������� �������, ����� ������ ����� � ��������� ����� �� ���������, � ����� ����� �������� �� ��������� ���������.

Input Format
�� ������� ��� �� ������������ ���� �� ������� ���� ����� N, ����� �� ���������� � �������. �� ���������� N ���� �� �������� ���������� �����, ���� � ������ ������, ��������� 
� ���� ��������. �� ���������� ��� �� ����� �� ������� ����������� ����� �� ���������.

Constraints
1 <= N <= 500
10000 <= ���������� ����� < 100000
1 <= ���� <= 4
2 <= ������ <= 6
Output Format
�� ������������ ����� �� �� �������� ��� ����� ��������� � ���� ��������. ����� �� �� �������� �������� ����� �� ������� � ���� ���� ����� ��������, ����� �� ������� ���������.

Sample Input 0
5
38613 3 2.492
12494 3 5.568
18935 4 2.436
35935 2 4.184
28215 1 4.696
4.902
Sample Output 0
3.8752 1
Sample Input 1
10
17176 4 2.58
30502 4 3.4
10589 4 3.192
38710 3 5.984
17297 1 4.068
19393 3 4.648
40766 1 4.768
39741 4 5.272
28383 4 5.628
29548 3 3.456
5.312
Sample Output 1
4.2996 2
*/
struct Student
{
	unsigned int facNumber;
	unsigned int course;
	double mark;
};

void init(Student& student) {
	unsigned int FN;
	unsigned int _course;
	double _mark;
	
	do
	{
		std::cout << "Please write a valid FN: ";
		std::cin >> FN;
	} while (FN < 10000 || FN > 99999);

	//tuk FN veche e ok
	//sega za course
	do
	{
		std::cout << "Please write a valid course: ";
		std::cin >> _course;
	} while (_course < 1 || _course > 4);

	//sega i course e ok
	do
	{
		std::cout << "Please write a valid mark: ";
		std::cin >> _mark;
	} while (_mark < 2.0 || _mark > 6.0);
	student.facNumber = FN;
	student.course = _course;
	student.mark = _mark;

}

void print(const Student& student) {
	std::cout << student.facNumber << student.course << student.mark << "\n";
	return;
}

struct  Group
{
	Student* students;
	size_t size;
	double mark;
};

int numberOfStudentsGettingMoney(const Group& group, double neededMark) {
	int result = 0;
	for (size_t i = 0; i < group.size; i++)
	{
		if (group.students[i].mark >= neededMark) {
			result++;
		}
	}
	return result;
}

int main() {
	unsigned int numberOfStudents;
	std::cin >> numberOfStudents;	

	Group group;
	group.students = new(std::nothrow) Student[numberOfStudents];
	
	if (group.students == nullptr) {
		std::cerr << "There is a problem with creating a group!";
		return -1;
	}
	group.size = numberOfStudents;

	double totalMark = 0.0;
	for (size_t i = 0; i < group.size; i++)
	{
		init(group.students[i]);
		totalMark += group.students[i].mark;
	}

	//inicializirame srednata stoinost na ocnekite na grupata
	group.mark = totalMark / group.size;

	double minimalMarkForStipend;

	do
	{
		std::cout << "Please enter a minimal mark for getting a stipend!";
		std::cin >> minimalMarkForStipend;

	} while (minimalMarkForStipend < 2.0 || minimalMarkForStipend > 6.0);

	//sega e validna minimalnata ocenka za stipendiq
	int finalResult = numberOfStudentsGettingMoney(group, minimalMarkForStipend);
	std::cout << "FINAL RESULTS: " << group.mark  << " " << finalResult;
}