#include "Cat.hpp"
#include <iostream>

void Cat::Talk() const{
	std::cout << "Hello, I am a Cat!\n";
}

Animal *Cat::Clone() const{
	return new Cat(*this);
}