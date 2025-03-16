// Добре разписана задача
#include <iostream>
#include <cmath>
#define e 0.0001  //I wanted to use ε but idk if it will compile on other PCs :/

struct Equation {
	double a = 0;
	double b = 0;
	double c = 0;
};

double validateInput(char parameter) {
	double temp;
	std::cout << parameter << ": ";
	std::cin >> temp;
	while (temp < -100 || temp > 100) {
		std::cout << "Parameter must be in range -100 <= param <= 100" << std::endl;
		std::cout << parameter << ": ";
		std::cin >> temp;
	}

	return temp;
}

void findRoots(Equation& equation) {
	double d = equation.b * equation.b - 4 * equation.a * equation.c;
	if (d < 0) {
		std::cout << "The equation does not have real solutions!" << std::endl;
		return;
	}
	double x1 = (-1 * equation.b + sqrt(d)) / (2 * equation.a);
	double x2 = (-1 * equation.b - sqrt(d)) / (2 * equation.a);

	if (d - 0 < e) {
		std::cout << "x1 = x2 = " << x1 << std::endl;
		return;
	}
	
	if (x1 > x2) {
		x1 += x2;
		x2 = x1 - x2;
		x1 -= x2;
	}
	std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
}

int main() {
	double a = validateInput('a');
	double b = validateInput('b');
	double c = validateInput('c');

	Equation eqution = { a, b, c };
	findRoots(eqution);

	return 0;
}