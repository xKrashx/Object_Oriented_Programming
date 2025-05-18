#include "ShapeCollection/ShapeCollection.hpp"
#include "Factory/Factory.hpp"
#include <iostream>

int main(){

	ShapeCollection s;

	s.AddShape(Factory(ShapeType::Rectangle, 1, 1, 9, 9));
	s.AddShape(Factory(ShapeType::Triangle, 1, 2, 9, 4, 0, 0));
	s.AddShape(Factory(ShapeType::Circle, 3, 4, 1));

	std::cout << std::boolalpha << s[0] -> IsPointIn(3, 4.5) << '\n';
	std::cout << s[2] -> GetArea() << '\n';

}
