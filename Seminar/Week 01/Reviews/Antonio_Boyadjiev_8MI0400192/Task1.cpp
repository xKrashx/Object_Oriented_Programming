// Идеално разписана задача.
#include <iostream>
#include <cmath>

/*
������ 1: ������� �� ���� ����� N � ����� N ������������ � ���������, ���������� �� 3 �����(6 ����������).����������� ������������ ��������� �� ������ ��.

Input Format
�� ������� ��� �� ������� ���� ����� N, �� ���������� N ���� �� �������� �� 6 ���� �����, ������������ �� �����������.

Constraints
1 <= N <= 1000
- 100 <= xi, yi <= 100
Output Format
�� �� ��������� ������ �� ������ �����������, ��������� � ��������� ��� � ��������� � ���� ��������.

Sample Input
3
0 0 1 0 0 1
7 1 4 6 0 2
0 8 5 5 5 4
Sample Output
0.5 2.5 16
Explanation
������� ���������� ��� ���� 0.5, ������� ��� ���� 16, � ������� ��� ���� 2.5.� � �������� ��� �� 0.5, 2.5, 16.
*/

struct Point
{
	int x, y;
};

struct Triangle
{
	Point A, B, C;

	// За методи не е учено, но е добре написано.
	float area()const 
	{
		return std::abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
	}
};

void swap(Triangle& t1, Triangle& t2) {
	Triangle temp = t1;
	t1 = t2;
	t2 = temp;
}

void sort(Triangle* triangles,unsigned int num) {
	//selection sort -> izbirame nai-malkiq i go slapvame s nachalniqt, taka sortitrame ot nai-maluk -> nai-golqm
	for (size_t i = 0; i < num - 1; i++)
	{
		size_t minIndex = i;
		for (size_t j = i + 1; j < num; j++)
		{	
			//tekushtiqt e s po-malko lice, zatova trqbva da go otrazim
			if (triangles[j].area() < triangles[minIndex].area()) {
				minIndex = j;
			}
		}
		//ako sme namerili po-malko lice to swapvame,inache tekushtiqt e s nai-malko i e ok da produljim napred
		if (minIndex != i) {
			swap(triangles[i], triangles[minIndex]);
		}
	}
}


int main()
{
	unsigned int numberOfTriangles;
	std::cin >> numberOfTriangles;

	Triangle* triangles = new(std::nothrow) Triangle[numberOfTriangles]; // ��������� ����� �� �����������
	
	if(triangles == nullptr)
	{
		std::cerr << "No dynamicly allocated array of triangles!";
		return -1;
	}

	//����� �� ����� ������� ������� ����� �� �������������
	for (size_t i = 0; i < numberOfTriangles ; i++)
	{
		std::cin >> triangles[i].A.x >> triangles[i].A.y >> triangles[i].B.x >> triangles[i].B.y >> triangles[i].C.x >> triangles[i].C.y;
	}

	sort(triangles, numberOfTriangles);

	for (size_t i = 0; i < numberOfTriangles; i++)
	{
		std::cout << triangles[i].area() << " ";
	}
	
	delete[] triangles;

	return 0;
}
