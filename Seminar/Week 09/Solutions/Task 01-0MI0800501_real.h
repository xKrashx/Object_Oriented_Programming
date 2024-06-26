#pragma once
#include "Integer.h"
class Real : public Integer {
public:
	//void Copy(const Real& other);
	Real() = default;
	//Real(const Real& other);
	Real(const unsigned int& value_num, const bool& isneg, const unsigned int& den);
	unsigned int denominator;
	void Print()const;
};
