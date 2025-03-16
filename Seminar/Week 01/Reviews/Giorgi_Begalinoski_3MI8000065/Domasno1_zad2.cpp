#include <iostream>
#include <cmath>

struct QuadraticEquation {
	double a, b, c;

	// Отново същият коментар и тук.
	void solve() {
		if (a == 0) {
			std::cout << "The equation does not have real solutions!" << std::endl;
			return;
		}

		double discr = b * b - 4 * a * c;

		if (discr < 0) {
			std::cout << "The equation does not have real solutions!" << std::endl;
		}
		else if (discr == 0){
			double x = -b / (2 * a);
			std::cout << "x1 = x2 = " <<  x << std::endl;
		}
		else {
			double x1 = (-b - std::sqrt(discr)) / (2 * a);
			double x2 = (-b + std::sqrt(discr)) / (2 * a);
			std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
		}
	}
};

int main() {

	double a, b, c;
	std::cin >> a >> b >> c;

	if (a < -100 || a > 100 || b < -100 || b > 100 || c < -100 || c > 100) {
		std::cout << "Invalid input! Constrains : -100 <= a, b, c <= 100!" << std::endl;
		return 0;
	}

	QuadraticEquation equation{ a, b, c };
	equation.solve();

	return 0;
}