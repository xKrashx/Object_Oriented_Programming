#include <iostream>
// Тази библиотека ви е строго забранено да я ползвате,
// освен ако не е казано изрично, че можете.
#include <vector>
// Тази библиотека няма да ви е разрешена освен, ако не е опоменато.
// За базови сортиращи алгоритми трябва да сте говорили по УП.
#include <algorithm> //sort
#include <iomanip> //setprecision
// Липсва cmath библиотеката!

// Задача 2
struct QuadraticEquation {
	double a, b, c;

    // Отново, методи не са учени, но е добре написано.
    // Това го казвам, защото при контролните най-вече не е добре да се използва материал, който не е учен,
    // защото предизвиква съмнения за преписване и също така започва разпитване от преподавателите.
    // Така че се придържаме към това, което е учено до момента!
	void solve() const {
		double D = b * b - 4 * a * c;
		if (D > 0)
		{
			double x1 = (-b - std::sqrt(D)) / (2 * a);
			double x2 = (-b - std::sqrt(D)) / (2 * a);
			if (x1 > x2)
			{
				std::swap(x1, x2);
			}
			std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
			
		}
		else if (D == 0)
		{
			double x = -b / (2 * a);
			std::cout << "x1 = x2 = " << std::fixed << std::setprecision(6) << x << std::endl;
		}
		else if(D < 0)
		{
			std::cout << "The equation does not have real solutions!" << std::endl;
		}
	}
};

int main()
{
	QuadraticEquation eq;
	std::cin >> eq.a >> eq.b >> eq.c;
	eq.solve();
	return 0;
}