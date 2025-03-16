#include <iostream>

struct ComplexNumber
{
	int firstCoefficient;
	int secondCoefficient;
};

void readElements(ComplexNumber& z1, ComplexNumber& z2) {
	std::cin >> z1.firstCoefficient >> z1.secondCoefficient >> z2.firstCoefficient >> z2.secondCoefficient;
}

void checkIfCoefficientsAreValid(ComplexNumber& z1, ComplexNumber& z2) {
	if (z1.firstCoefficient < -1000 || z1.firstCoefficient > 1000
		|| z1.secondCoefficient < -1000 || z1.secondCoefficient > 1000
		|| z2.firstCoefficient < -1000 || z2.firstCoefficient > 1000
		|| z2.secondCoefficient < -1000 || z2.secondCoefficient > 1000)
	{
		std::cout << "Invalid input! Coefficients must be greater than -1000 and less than 1000!" << std::endl;
		// Отново същата забележка и тук.
		exit(1);
	}
}

// По-добър вариант е да направиш функцията да връща ComplexNumber и да го създадеш направо вътре в нея.
// Това важи и за долните 2 функции.
void addition(ComplexNumber& z1, ComplexNumber& z2, int& realPart, int& imaginaryPart) {
	realPart = z1.firstCoefficient + z2.firstCoefficient;
	imaginaryPart = z1.secondCoefficient + z2.secondCoefficient;
}

void subtraction(ComplexNumber& z1, ComplexNumber& z2, int& realPart, int& imaginaryPart) {
	realPart = z1.firstCoefficient - z2.firstCoefficient;
	imaginaryPart = z1.secondCoefficient - z2.secondCoefficient;
}

void multiplication(ComplexNumber& z1, ComplexNumber& z2, int& realPart, int& imaginaryPart) {
	realPart = z1.firstCoefficient * z2.firstCoefficient;
	realPart += z1.secondCoefficient * z2.secondCoefficient * -1;

	imaginaryPart = (z1.secondCoefficient * z2.firstCoefficient) + (z2.secondCoefficient * z1.firstCoefficient);
}

// Следващите 3 функции можеха да са просто една функция.
// Това да копираме един и същи код е лоша практика, но в този курс
// ще ви обясним за добрата абстракция и как да се опитваме да я постигнем.
void printAddition(int& realPart, int& imaginaryPart) {

	if (realPart == 0)
		std::cout << "Addition: " << imaginaryPart << "i" << std::endl;
	else if (imaginaryPart == 0) 
		std::cout << "Addition: " << realPart << std::endl;
	else if (imaginaryPart < 0)
		std::cout << "Addition: " << realPart << " - " << -imaginaryPart << "i" << std::endl;
	else
		std::cout << "Addition: " << realPart << " + " << imaginaryPart << "i" << std::endl;
}

void printSubtraction(int& realPart, int& imaginaryPart) {

	if (realPart == 0)
		std::cout << "Subtraction: " << imaginaryPart << "i" << std::endl;
	else if (imaginaryPart == 0)
		std::cout << "Subtraction: " << realPart << std::endl;
	else if (imaginaryPart < 0)
		std::cout << "Subtraction: " << realPart << " - " << -imaginaryPart << "i" << std::endl;
	else 
		std::cout << "Subtraction: " << realPart << " - " << imaginaryPart << "i" << std::endl;
}

void printMultiplication(ComplexNumber& z1, ComplexNumber& z2, int& realPart, int& imaginaryPart) {

	if (realPart == 0)
		std::cout << "Multiplication: " << imaginaryPart << "i" << std::endl;
	else if (imaginaryPart == 0)
		std::cout << "Multiplication: " << realPart << std::endl;
	else
		std::cout << "Multiplication: " << realPart << " + " << imaginaryPart << "i" << std::endl;
}



int main() {
	ComplexNumber z1;
	ComplexNumber z2;

	readElements(z1, z2);

	checkIfCoefficientsAreValid(z1, z2);

	int realPart = 0;
	int imaginaryPart = 0;

	addition(z1, z2, realPart, imaginaryPart);
	printAddition(realPart, imaginaryPart);

	subtraction(z1, z2, realPart, imaginaryPart);
	printSubtraction(realPart, imaginaryPart);

	multiplication(z1, z2, realPart, imaginaryPart);
	printMultiplication(z1, z2, realPart, imaginaryPart);

	return 0;
}