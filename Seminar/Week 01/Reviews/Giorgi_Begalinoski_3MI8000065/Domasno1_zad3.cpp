#include <iostream>
#include <cmath>

struct ComplexNumber {
	int realPart;
	int imagineryPart;

	void print() {
		std::cout << realPart;
		if (imagineryPart != 0) {
			std::cout << (imagineryPart > 0 ? " + " : " - ") << std::abs(imagineryPart) << "i";
		}
		std::cout << std::endl;
	}
};

// Идеята на следващите три функции не е да показват само резултатът от действието,
// ами да връщат обект, който го репрезентира.
// Какво става ако искам да събера 3 комплексни числа?
// Искам да направя z4 = add(z1, z2) и после result = add(z3, z4).
void addComplexNumbers(ComplexNumber z1, ComplexNumber z2) {
	ComplexNumber newZ;
	newZ.realPart = z1.realPart + z2.realPart;
	newZ.imagineryPart = z1.imagineryPart + z2.imagineryPart;
	newZ.print();
}

void subtractComplexNumbers(ComplexNumber z1, ComplexNumber z2) {
	ComplexNumber newZ;
	newZ.realPart = z1.realPart - z2.realPart;
	newZ.imagineryPart = z1.imagineryPart - z2.imagineryPart;
	newZ.print();
}

void multiplyComplexNumbers(ComplexNumber z1, ComplexNumber z2) {
	ComplexNumber newZ;
	newZ.realPart = z1.realPart * z2.realPart - z1.imagineryPart * z2.imagineryPart;
	newZ.imagineryPart = z1.realPart * z2.imagineryPart + z1.imagineryPart * z2.realPart;
	newZ.print();
}


int main() {
	
	ComplexNumber z1;
	std::cin >> z1.realPart >> z1.imagineryPart;
	ComplexNumber z2;
	std::cin >> z2.realPart >> z2.imagineryPart;

	addComplexNumbers(z1, z2);
	subtractComplexNumbers(z1, z2);
	multiplyComplexNumbers(z1, z2);
	return 0;
}