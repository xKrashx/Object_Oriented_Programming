#include "Real.h"

void Real::Print()const {
	double res;
	if (!isNegative) {
		res = (double)num / (double)denominator;
	}
	else {
		res = -1 * ((double)num / (double)denominator);
	}
	std::cout << res;
}

Real::Real(const unsigned int& value_num, const  bool& isneg,const unsigned int& den):Integer(value_num, isneg) {
	this->denominator = den;
}
