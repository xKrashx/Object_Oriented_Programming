#include <iostream>
#include<cmath>
#define MIN_N 1
#define MAX_N 1000

//double area = (1 / 2) * abs((x1 * (y2-y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))); ---> formula

struct Point {
	int x;
	int y;
};

struct Triangle {
	Point p1;
	Point p2;
	Point p3;
};

void readCoordinates(Point &point) {
	std::cin >> point.x;
	std::cin >> point.y;

	if (point.x < -100 || point.x > 100 || point.y < -100 || point.y > 100) 
	{
		std::cout << "Invalid coordinates!";
		// exit е системен примитив, който препоръчвам строго да се избягва.
		// Това е защото, той директно приключва процеса без да развива стека
		// и да освобождава динамично заделената памет.
		// Твърде възможно е при грешна употреба да се таксува тежко на контролно/изпит.
		exit(1);
	}
}

void readTriangle(Triangle &triangle) {
	readCoordinates(triangle.p1);
	readCoordinates(triangle.p2);
	readCoordinates(triangle.p3);
}

double findAreaOfTriangle(Triangle const &triangle)
{
	return (0.5) * abs(
		(triangle.p1.x * (triangle.p2.y - triangle.p3.y)) 
		+ (triangle.p2.x * (triangle.p3.y - triangle.p1.y)) 
		+ (triangle.p3.x * (triangle.p1.y - triangle.p2.y)));
}

void sortedByAreaTriangles(int n, double* areaArray)
{

	for (unsigned int i = 0; i < n - 1; i++)
	{
		unsigned int minIndex = i;

		for (unsigned int j = i + 1; j < n; j++)
		{
			if (areaArray[j] < areaArray[i]) {
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			double temp = areaArray[i];
			areaArray[i] = areaArray[minIndex];
			areaArray[minIndex] = temp;
		}
	}

}

void printAreas(int n, double* const areaArray) {

	for (unsigned int i = 0; i < n; i++)
	{
		std::cout << areaArray[i] << " ";
	}

}


int main() {

	std::cout << "Please enter the count of triangles: ";

	int n;
	std::cin >> n;

	if (n < MIN_N || n > MAX_N )
	{
		std::cout << "Invalid input!";
		return 1;
	}

	Triangle* triangleArray = new Triangle[n];
	std::cout << "Please enter the coordinates of the " << n <<" triangles: " << std::endl;
 

	for (unsigned int i = 0; i < n; i++)
	{
		readTriangle(triangleArray[i]);
	}


	// От тук надолу мога да считам, че не се следва коректно условието.
	// Резултатът, който ще е изкаран на екрана е коректен, но не и начина, по който е изкаран.
	// В условието се изискваше да се сортират триъгълници, а не просто лица.
    // Това е същото като да ти дам за задача да сортираш шишета на рафт спрямо височината им и ти се върнеш с един лист,
    // на който си написал височините в сортиран ред. Реално заобикаляш проблема.
    // За такива уточнения на контролно и изпит е напълно възможно да ти се анулира задачата, защото не е по условието.
	double* areaArray = new double[n];

	for (unsigned int i = 0; i < n; i++)
	{
		areaArray[i] = findAreaOfTriangle(triangleArray[i]);
	}

	sortedByAreaTriangles(n, areaArray);

	std::cout << std::endl << "The sorted areas of the triangles are: ";
	printAreas(n, areaArray);

	delete[] triangleArray;
	delete[] areaArray;
	return 0;
}