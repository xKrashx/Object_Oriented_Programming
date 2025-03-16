// Добре написана задача. С малки забележки. (9/10)

#include <iostream>
// memory библиотеката няма да ти трябва. За динамичната памет ни трябва new.
#include <memory>
// Използвай си C++ еквивалента, който е cmath
#include <math.h>
struct Point
{
	int x;
	int y;
};
struct Triangle
{
	Point A;
	Point B;
	Point C;
	float area;
};


// Защо трябва да подаваме i? Не можем ли просто да я дефинираме вътре във функцията променливата и ефекта да е същият.
int enterCoordinate(int i)
{
	std::cin >> i;
	while (i < -100 || i > 100)
	{
		std::cout << "Reenter coordinate of triangle(1 <= N <= 1000): ";
		std::cin >> i;
	}
	return i;
}

void enterPoint(Point& point)
{
	std::cout << "Enter x: ";
	point.x = enterCoordinate(point.x);
	std::cout << "Enter y: ";
	point.y = enterCoordinate(point.y);
}

void enterTriangle(Triangle& tr)
{
	enterPoint(tr.A);
	enterPoint(tr.B);
	enterPoint(tr.C);
}

void printPoint(const Point& p)
{
	std::cout << "(" << p.x << ", " << p.y << ")";
}

void printTriangle(const Triangle& tr)
{
	printPoint(tr.A);
	printPoint(tr.B);
	printPoint(tr.C);
	std::cout << "Area: " << tr.area;
}

void calcAreaOfTriangle(Triangle& tr)
{
	tr.area = 0.5 * fabs(tr.A.x * (tr.B.y - tr.C.y) +
		tr.B.x * (tr.C.y - tr.A.y) +
		tr.C.x * (tr.A.y - tr.B.y));
}

void swap(float& a, float& b)
{
	float temp = a;
	a = b;
	b = temp;
}

void sortByArea(Triangle* tr, const int size)
{
	for (size_t i = 0; i < size-1; i++)
	{
		int min = i;
		for (size_t j = i+1; j < size; j++)
		{
			if (tr[j].area < tr[min].area)
			{
				min = j;
			}
		}
		swap(tr[i].area, tr[min].area);
	}
}

int main()
{
	// Размера е хубаво да бъде size_t, макар и да си се погрижил за валидацията да е коректна.
	int nTimes = 0;
	Triangle tr = {};
	std::cout << "Enter how many n: ";
	std::cin >> nTimes;
	while (nTimes < 1 || nTimes > 1000)
	{
		std::cout << "Reenter how many n(1 <= N <= 1000): ";
		std::cin >> nTimes;
	}
	int i = 0; //counting
	int time = nTimes;
	Triangle* triangles = new(std::nothrow) Triangle[nTimes];
	if (triangles == nullptr)
	{
		std::cout << "Memory error";
		// Този delete не чупи нещата, но е излишен.
		// Ние влизаме в този if, защото НЕ сме успели да заделим памет.
		// Тогава какво освобождаваме?
		delete[] triangles;
		return -1;
	}
	while (time)
	{
		std::cout << "Triangle " << i + 1 << '\n';
		// Тука можеше просто да подаваш triangles[i], вместо да имаш отделен обект,
		// който да копираш на всяка клетка.
		enterTriangle(tr);
		calcAreaOfTriangle(tr);
		triangles[i] = tr;
		i++;
		time--;
		std::cout << "\n";
	}

	sortByArea(triangles, nTimes);

	//prints
	for (size_t i = 0; i < nTimes; i++)
	{
		printTriangle(triangles[i]);
		// puts го забравяме!!!
		puts("");
	}


	delete[] triangles;
	return 0;
}