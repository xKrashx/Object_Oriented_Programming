// Като изключим забележките съм много доволен как е написана задачата.
#include <iostream>
#include <new>
// Тази библиотека ви е забранена за използване, освен ако не е казано противно в условието.
#include <algorithm>
#include <cmath>

// Структурата е добре написана, но нека не избързваме с материала.
// Модификатори за достъп, конструктори и методи ще учим нататък в курса.
// Желателно е да се придържаш към материала, който сме взели особено на контролно/изпит,
// защото иначе ще започнат едни неудобни въпроси от наша страна.
struct Triangle
{
private:
	int x1, y1, x2, y2, x3, y3;

public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		this->x3 = x3;
		this->y3 = y3;
	}

	double area() {
		return std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
	}


};


int main() {

	unsigned n;
	std::cin >> n;

	if (n < 1 || n > 1000) return -1;

    // В условието се изискваше да се сортират триъгълници, а не просто лица.
    // Това е същото като да ти дам за задача да сортираш шишета на рафт спрямо височината им и ти се върнеш с един лист,
    // на който си написал височините в сортиран ред. Реално заобикаляш проблема.
    // За такива уточнения на контролно и изпит е напълно възможно да ти се анулира задачата, защото не е по условието.
	double* areasPtr = new(std::nothrow) double[n];

	if (!areasPtr) {
		std::cout << "Allocation problem" << std::endl;
		return -1;
	}

	for (unsigned i = 0; i < n; i++) {
		int x1, y1, x2, y2, x3, y3;
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		Triangle triangle(x1, y1, x2, y2, x3, y3);
		areasPtr[i] = triangle.area();
	}

	std::sort(areasPtr, areasPtr + n);
	
	for (unsigned i = 0; i < n; i++) {
		std::cout << areasPtr[i] << " ";

	}

	delete[] areasPtr;

	return 0;
}