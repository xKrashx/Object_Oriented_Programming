#include "Complex.h"
Complex::Complex(const unsigned& num, const bool& isneg, const unsigned& den, const Real& img): Real(num, isneg, den){
	this->imaginary = img;
}
void Complex::Print()const {
	double real;
	real = (double)num / (double)denominator;
	if (isNegative) {
		real *= -1;
	}
	std::cout << real;
	imaginary.Print();
	std::cout << "*i" << std::endl;
	
}
