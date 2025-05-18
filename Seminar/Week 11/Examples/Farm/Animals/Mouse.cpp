#include "Mouse.hpp"
#include <iostream>

void Mouse::Talk() const{
	std::cout << "Hello, I am a Mouse!\n";
}

Animal *Mouse::Clone() const{
	return new Mouse(*this);
}