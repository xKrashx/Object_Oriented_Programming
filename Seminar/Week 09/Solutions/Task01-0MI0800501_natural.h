#pragma once
#include <iostream>
class Natural {
public:
	Natural() = default;
	Natural(const unsigned int& value): num(value){}
	unsigned int num;
	void Print()const;

private:

};
