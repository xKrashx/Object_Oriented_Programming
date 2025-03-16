#include <iostream>

// Отново задачата не е по условието, тъй като не се използват никакви структури!

void readComplexNumbers(int& a, int& b, int& c, int&d) {
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;

	while (-1000 > a || 1000 < a || -1000 > b || 1000 < b || -1000 > c || 1000 < c || -1000 > d || 1000 < d) {
		std::cout << "Invalid input!!! \n a,b,c,d must be >= -1000 and <= 1000 !" << std::endl;
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;
		std::cin >> d;
	}
}

void addComplexNumbers(int a, int b, int c, int d, int& r1, int& r2) {
	r1 = a + c;
	r2 = b + d;
}

void subtractComplexNumbers(int a, int b, int c, int d, int& r1, int& r2) {
	r1 = a - c;
	r2 = b - d;
}

void multiplyComplexNumbers(int a, int b, int c, int d, int& r1, int& r2) {
	//(a + bi) * (c + di)
	r1 = a * c - b * d;
	r2 = a * d + b * c;
}

void printComplexNumber(int a, int b) {
	if (b == 0) {
		std::cout << a << std::endl;
		return;
	}
	if (a == 0) {
		std::cout << b << "i" << std::endl;
		return;
	}
	if (b < 0) {
		std::cout << a << b << "i" << std::endl;
		return;
	}
	std::cout << a << "+" << b << "i" << std::endl;
}

int main3() {
	int a, b, c, d;
	readComplexNumbers(a,b,c,d);

	int r1, r2;
	addComplexNumbers(a, b, c, d, r1, r2);
	printComplexNumber(r1, r2);
	subtractComplexNumbers(a, b, c, d, r1, r2);
	printComplexNumber(r1, r2);
	multiplyComplexNumbers(a, b, c, d, r1, r2);
	printComplexNumber(r1, r2);

	return 0;
}