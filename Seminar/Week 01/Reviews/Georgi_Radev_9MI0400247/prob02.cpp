#include <iostream>
#include <cmath>

const double EPS = 1e-9;

struct QuadraticEquation {
	double a;
	double b;
	double c;
};

void readEquation(QuadraticEquation& eq);
void printSolution(const QuadraticEquation& eq);
double mod(double a);

int main() {
	QuadraticEquation equation;
	readEquation(equation);
	printSolution(equation);

	return 0;
}

void readEquation(QuadraticEquation& eq) {
	std::cin >> eq.a >> eq.b >> eq.c;
}
void printSolution(const QuadraticEquation& eq) {
	double d = eq.b*eq.b - 4 * eq.a*eq.c;
	if (d < 0) {
		std::cout << "The equation does not have real solutions!";
	}
	else if ((mod(d) - EPS) < 0) {
		std::cout << "x1 = x2 = " << - eq.b/(2* eq.a);
	}
	else {
		double s = sqrt(d);
		std::cout << "x1 = " << (-eq.b - s) / 2 * eq.a <<
			" x2 = " << (-eq.b + s) / 2 * eq.a;
	}
	std::cout << std::endl;
}

double mod(double a) {
	return a < 0 ? -a : a;
}