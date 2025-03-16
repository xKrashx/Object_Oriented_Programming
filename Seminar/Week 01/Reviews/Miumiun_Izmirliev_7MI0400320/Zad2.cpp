#include <iostream>
// Липсва cmath библиотеката


// Отново задачата не е по условието, тъй като не се използват никакви структури!

void readQuadraticParams(int& a, int& b, int& c) {
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	while (-100 > a || 100 < a || -100 > b || 100 < b || -100 > c || 100 < c) {
		std::cout << "Invalid input!!! \n a,b,c must be >= -100 and <= 100 !" << std::endl;
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;
	}
}

int getQuadraticSolutions(int a ,int b ,int c, double* result) {
	double d = b * b - 4 * a * c;
	if (d < 0) {
		return 0;
	}
	if (d == 0) {
		double x1 = (-b + d) / (2 * a);
		result[0] = x1;
		return 1;
	}
	d = sqrt(d);
	double x1 = (-b + d) / (2 * a);
	double x2 = (-b - d) / (2 * a);

	if (x1 > x2) {
		result[0] = x2;
		result[1] = x1;
	}
	else {
		result[0] = x1;
		result[1] = x2;
	}
	return 2;
}

int main2() {
	int a, b, c;
	readQuadraticParams(a,b,c);

	double result[2];
	int answers = getQuadraticSolutions(a,b,c,result);

	if (answers == 0) {
		std::cout << "The equation does not have real solutions!" << std::endl;
	}
	else if (answers == 1) {
		std::cout << "x1 = x2 = " << result[0] << std::endl;
	}
	else {
		std::cout << "x1 = " << result[0] << ", x2 = " << result[1] << std::endl;
	}
	return 0;
}