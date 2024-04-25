#include <iostream>

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

void PrintAreas(Shape const **shapes, size_t shapesCount){

	for(size_t i = 0; i < shapesCount; ++i)
		std::cout << shapes[i]->GetArea() << '\n';
}
void PrintPers(Shape const **shapes, size_t shapesCount){

	for(size_t i = 0; i < shapesCount; ++i)
		std::cout << shapes[i]->GetPer() << '\n';

}

void CheckPointIn(Shape const **shapes, size_t shapesCount, int x, int y){

	for(size_t i = 0; i < shapesCount; ++i)
		std::cout << shapes[i]->IsPointIn(x,y) << '\n';

}

void FreeCollection(Shape const **shapes, size_t shapesCount){

	for(size_t i = 0; i < shapesCount; ++i)
		delete shapes[i];
	delete[] shapes;

}

int main(){

	Shape **arr = new Shape *[4];

	arr[0] = new Rectangle(3, 4, 6, 8);
	arr[1] = new Circle(3, 3, 4);
	arr[2] = new Circle(1, 4, 5);
	arr[3] = new Triangle(1, 1, 2, 2, 3, 3);

	PrintAreas(arr, 4);
	std::cout << '\n';

	PrintPers(arr, 4);
	std::cout << '\n';

	CheckPointIn(arr, 4, 3, 3);

	FreeCollection(arr, 4);

	return 0;
	
}
