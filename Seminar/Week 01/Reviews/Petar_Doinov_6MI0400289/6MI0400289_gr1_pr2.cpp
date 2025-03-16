#include <iostream>
#include <cmath>

// Същите забележки както за 1ва задача отнасящи се за входа.
void clearInput() {
	char c = 0;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

float validFloat() {
	float temp = -1000;
	do {
		char c = std::cin.peek();
		while (c != '-' && (c < '0' || c > '9')) {
			std::cin.ignore();
			c = std::cin.peek();
		}
		c = getchar();
		if (c == '-') {
			c = std::cin.peek();
			if (c < '0' || c > '9') {
				continue;
			}
		}
		std::cin.unget();
		std::cin >> temp;
		if (temp < -100 || temp > 100) {
			std::cout << "Invalid Input. Please enter a number between -100 and 100." << std::endl;
		}
	} while (temp < -100 || temp > 100);
	return temp;
}

float Discriminant(const float a, const float b, const float c) {
	return (b * b - 4 * a * c);
}

void Solve(const float a, const float b, const float c) {
	float dis = Discriminant(a, b, c), root1 = 0, root2 = 0;
	if (dis < 0) {
		std::cout << "The equation does not have real solutions!" << std::endl;
	}
	else if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				std::cout << "The equation is true for every x." << std::endl;
			}
			else {
				std::cout << "The equation does not have real solutions!" << std::endl;
			}
		}
		else {
			root1 = -c / b;
			std::cout << "x = " << root1 << std::endl;
		}
	}
	else if (dis == 0) {
		root1 = -(b / (2 * a));
		std::cout << "x1 = x2 = " << root1 << std::endl;
	}
	else {
		root1 = -(b + std::sqrt(dis)) / (2 * a);
		root2 = -(b - std::sqrt(dis)) / (2 * a);
		if (root1 > root2) {
			float temp = root1;
			root1 = root2;
			root2 = temp;
		}
		std::cout << "x1 = " << root1 << ", x2 = " << root2 << std::endl;
	}
}

int main() {
	float a = 1, b = 2.5, c = 1;
	a = validFloat();
	b = validFloat(); 
	c = validFloat();
	std::cout << a << " " << b << " " << c << std::endl;
	//float test = Discriminant(a, b, c);
	//std::cout << test;
	Solve(a, b, c);
}