#include "Dog.hpp"
#include <iostream>

void Dog::Talk() const{
	std::cout << "Hello, I am a Dog!\n";
}

Animal *Dog::Clone() const{
	return new Dog(*this);;
}