#pragma once
#include "Natural.h"
class Integer :public Natural {
public:
	Integer() = default;
	Integer(const unsigned int& value, const bool& sign);
	bool isNegative;
	void Print()const;

};
