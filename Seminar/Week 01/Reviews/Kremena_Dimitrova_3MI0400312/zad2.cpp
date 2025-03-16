#include <iostream>
#include <cmath>

// По условие се изискваше да пазите реални числа, а не цели!
struct QuadraticEquation
{
	int a;
	int b;
	int c;
};

void readElements(QuadraticEquation& equation) {
	std::cin >> equation.a >> equation.b >> equation.c;
}
void checkIfCoefficientsAreValid(QuadraticEquation& equation) {
	if (equation.a < -100 || equation.a > 100
		|| equation.b < -100 || equation.b > 100
		|| equation.c < -100 || equation.c > 100)
	{
		std::cout << "Invalid input! Coefficients must be greater than -100 and less than 100!" << std::endl;
		// Отново същата забележка с exit.
		exit(1);
	}
}

int findTheDiscriminant(QuadraticEquation& equation) {
	return (equation.b * equation.b) - 4 * (equation.a * equation.c);
}

double findX1(QuadraticEquation& equation, int theDiscriminant) {
	return ((-equation.b) - sqrt(theDiscriminant)) / (2 * equation.a);
}

double findX2(QuadraticEquation& equation, int theDiscriminant) {
	return ((-equation.b) + sqrt(theDiscriminant)) / (2 * equation.a);
}

int main() {
	QuadraticEquation equation;

	std::cout << "Please enter exactly 3 coefficients: " << std::endl;

	readElements(equation);
	checkIfCoefficientsAreValid(equation);

	int theDiscriminant = findTheDiscriminant(equation);

	if (theDiscriminant < 0) {
		std::cout << "The equation does not have real solutions!" << std::endl;
		return 0;
	} else if (theDiscriminant == 0) {
		std::cout << "x1 = x2 = " << (- equation.b) / (2.0 * equation.a) << std::endl;
	} else {
		double x1 = findX1(equation, theDiscriminant);
		double x2 = findX2(equation, theDiscriminant);

		if (x1 < x2) 
			std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
		else
			std::cout << "x1 = " << x2 << ", x2 = " << x1 << std::endl;
	}

	return 0;
}