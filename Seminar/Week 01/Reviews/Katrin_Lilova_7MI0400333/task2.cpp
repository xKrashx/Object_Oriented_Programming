// Идеално разписана задача
#include "task2.hpp"
#include <cmath>
#include <iostream>

namespace Task2 {
	bool hasRealRoots(const QuadraticEquation& eq) {
		return eq.discriminant >= 0;
	}

	void findRoots(QuadraticEquation& eq) {
		if (eq.discriminant == 0) {
			double x = -eq.b / (2 * eq.a);
			eq.root1 = x;
			eq.root2 = x;
		}
		else {
			double x1 = (-eq.b + std::sqrt(eq.discriminant)) / (2 * eq.a);
			eq.root1 = x1;

			double x2 = (-eq.b - std::sqrt(eq.discriminant)) / (2 * eq.a);
			eq.root2 = x2;
		}
	}

	void setDiscriminant(QuadraticEquation& eq) {
		double d = eq.b * eq.b - 4 * eq.a * eq.c;
		eq.discriminant = d;
	}

	int run() {
		QuadraticEquation eq;
		std::cout << "Enter coefficients:" << "\n";

		do {
			std::cin >> eq.a >> eq.b >> eq.c;
		} while (eq.a < COEF_VALUE_MIN || eq.a > COEF_VALUE_MAX ||
			eq.b < COEF_VALUE_MIN || eq.b > COEF_VALUE_MAX ||
			eq.c < COEF_VALUE_MIN || eq.c > COEF_VALUE_MAX);

		setDiscriminant(eq);

		if (!hasRealRoots(eq)) {
			std::cout << "No real roots." << "\n";

			return 1;
		}

		findRoots(eq);
		std::cout << "x1 = " << eq.root1 << ", x2 = " << eq.root2 << "\n";

		return 0;
	}
}