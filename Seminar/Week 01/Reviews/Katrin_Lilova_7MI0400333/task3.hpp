#pragma once

namespace Task3 {
	const int COEF_VALUE_MAX = 1000;
	const int COEF_VALUE_MIN = -1000;

	struct ComplexNumber {
		int real;
		int imaginary;
	};

	int run();
	void print(const ComplexNumber& num);

	ComplexNumber add(const ComplexNumber& z1, const ComplexNumber& z2);
	ComplexNumber multiply(const ComplexNumber& z1, const ComplexNumber& z2);
	ComplexNumber subtract(const ComplexNumber& z1, const ComplexNumber& z2);
}