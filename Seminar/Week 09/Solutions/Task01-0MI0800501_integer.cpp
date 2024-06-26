#include "Integer.h"

void Integer::Print()const {
	if (isNegative) {
		std::cout << "-" << this->num << std::endl;
	}
	else {
		std::cout << this->num << std::endl;
	}
}
Integer::Integer(const unsigned int& value, const bool& isneg) :Natural(value) {
	this->isNegative = isneg;
}
