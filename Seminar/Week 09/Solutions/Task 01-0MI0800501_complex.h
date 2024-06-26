#pragma once
#include "Real.h"
class Complex:public Real {
public:
	Real imaginary;
	Complex() = default;
	Complex(const unsigned& num, const bool& isneg, const unsigned& den, const Real& img);
	void Print()const;
	
};
