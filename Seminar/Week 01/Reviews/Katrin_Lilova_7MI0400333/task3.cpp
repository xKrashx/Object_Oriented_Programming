// Идеално разписана задача
#include "task3.hpp"
#include <iostream>

namespace Task3 {
	ComplexNumber add(const ComplexNumber& z1, const ComplexNumber& z2) {
		return { z1.real + z2.real, z1.imaginary + z2.imaginary };
	}

	ComplexNumber multiply(const ComplexNumber& z1, const ComplexNumber& z2) {
		return {
			z1.real * z2.real - z1.imaginary * z2.imaginary,
			z1.real * z2.imaginary + z1.imaginary * z2.real
		};
	}

	ComplexNumber subtract(const ComplexNumber& z1, const ComplexNumber& z2) {
		return { z1.real - z2.real, z1.imaginary - z2.imaginary };
	}

	void print(const ComplexNumber& num) {
		std::cout << num.real;

		if (num.imaginary >= 0) {
			std::cout << "+" << num.imaginary << "i\n";
		}
		else {
			std::cout << "-" << -num.imaginary << "i\n";
		}
	}

	int run() {
		int a, b, c, d;
		std::cout << "Enter coefficients:" << "\n";

		do {
			std::cin >> a >> b >> c >> d;
		} while (a < COEF_VALUE_MIN || a > COEF_VALUE_MAX ||
			b < COEF_VALUE_MIN || b > COEF_VALUE_MAX ||
			c < COEF_VALUE_MIN || c > COEF_VALUE_MAX ||
			d < COEF_VALUE_MIN || d > COEF_VALUE_MAX);

		ComplexNumber z1, z2;

		z1.real = a;
		z1.imaginary = b;

		z2.real = c;
		z2.imaginary = d;

		print(add(z1, z2));
		print(subtract(z1, z2));

		print(multiply(z1, z2));
		return 0;
	}
}