#include <cmath>
#include <iostream>
#include "triangle.hpp"

double twoDotsDistance(double Ax, double Ay, double Bx, double By) {
	return sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
};

void triangleArea(Triangle& triangle) {
	double a = twoDotsDistance(triangle.Bx, triangle.By, triangle.Cx, triangle.Cy);
	double b = twoDotsDistance(triangle.Ax, triangle.Ay, triangle.Cx, triangle.Cy);
	double c = twoDotsDistance(triangle.Ax, triangle.Ay, triangle.Bx, triangle.By);

	//std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << c << std::endl;


	if (a + b <= c || a + c <= b || b + c <= a) {
		std::cout << "Invalid triangle coordinates" << std::endl;
		triangle.area = -1;
		return;
	}

	double p = (a + b + c) / 2;
	double area = sqrt(p * (p - a) * (p - b) * (p - c));
	//area = std::round(area * 1000) / 1000;
	triangle.area = area;
};

double validateCoordinates(const char name[3]) {
	double temp = -1;
	std::cout << name << ": ";
	std::cin >> temp;

	while (temp < -100 || temp > 100) {
		std::cout << "Invalid input! Try again!" << std::endl;
		std::cout << name << ": ";
		std::cin >> temp;
	}

	return temp;
}

void triangleBuilder(Triangle& triangle) {
	std::cout << "Enter the coordinates of the triangle's dots.\nConstraints: -100 <= xi, yi <= 100" << std::endl;
	triangle.Ax = validateCoordinates("Ax");
	triangle.Ay = validateCoordinates("Ay");
	triangle.Bx = validateCoordinates("Bx");
	triangle.By = validateCoordinates("By");
	triangle.Cx = validateCoordinates("Cx");
	triangle.Cy = validateCoordinates("Cy");

	triangleArea(triangle);
};
