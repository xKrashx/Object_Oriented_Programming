#include <iostream>

// Същите забележки за входа.
void clearInput() {
	char c = 0;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

int validInt() {
	int temp = -10000;
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
		//std::cout << temp << std::endl;
		if (temp < -1000 || temp > 1000) {
			std::cout << "Invalid input, try again." << std::endl;
			clearInput();
		}
	} while (temp < -1000 || temp > 1000);
	return temp;
}

struct complexInt {
	int Re;
	int Im;
};

// Това не трябва да връща референция!
// Както и другите функции по-надолу
complexInt& readComplexInt() {
	complexInt temp;
	temp.Re = validInt();
	temp.Im = validInt();
	return temp;
}

void printComplexInt(complexInt& cint) {
	if (cint.Im == 0) {
		std::cout << cint.Re << std::endl;
	}
	else if (cint.Re == 0) {
		std::cout << cint.Im << 'i' << std::endl;
	}
	else if (cint.Im > 0) {
		std::cout << cint.Re << "+" << cint.Im << 'i' << std::endl;
	}
	else {
		std::cout << cint.Re << cint.Im << 'i' << std::endl;
	}
}
	
complexInt& sum(const complexInt& first, const complexInt& second) {
	complexInt temp;
	temp.Re = first.Re + second.Re;
	temp.Im = first.Im + second.Im;
	return temp;
}

complexInt& difference(const complexInt& first, const complexInt& second) {
	complexInt temp;
	temp.Re = first.Re - second.Re;
	temp.Im = first.Im - second.Im;
	return temp;
}

complexInt& product(const complexInt& first, const complexInt& second) {
	complexInt temp;
	temp.Re = (first.Re * second.Re) - (first.Im * second.Im);
	temp.Im = (first.Re * second.Im) + (first.Im * second.Re);
	return temp;
}

int main() {
	complexInt num1 = readComplexInt();
	complexInt num2 = readComplexInt();
	complexInt Sum = sum(num1, num2);
	complexInt Dif = difference(num1, num2);
	complexInt Prod = product(num1, num2);
	//printComplexInt(sum(num1, num2));
	printComplexInt(Sum);
	printComplexInt(Dif);
	printComplexInt(Prod);
}