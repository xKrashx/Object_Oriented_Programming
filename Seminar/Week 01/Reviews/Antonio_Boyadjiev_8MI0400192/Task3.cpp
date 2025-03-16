// Идеално разписана задача.
#include <iostream>
#include<cmath>

/*
* 
������ 3: �� �� ������� ��������� ����� ��������� ���������� �����. �������� �������, ����� ������, �������� � ��������� ��� ���������� �����.
�������� ��������� ������� �� ��������� ���������� �� ���������� �����.

Input Format
�� ������� ��� �� ������������ ���� �� ������������ ����, �� ����� �������� 4 ���� ����� a, b, c, d, ������������� �� ������������ �����(z1 = a + bi, z2 = c + di).

Constraints
-1000 <= a, b, c, d <= 1000
Output Format
�� ������������ ����� �� �� ��������� ����������� �� 3�� �������� ��������, ��������� � ��������� �� ����� �����. ����� �������� �� � �� ��� ���.

Sample Input 0
6 -4 10 7
Sample Output 0
16+3i
-4-11i
88+2i
Sample Input 1
-7 0 9 0
Sample Output 1
2
-16
-63
Sample Input 2
5 0 5 5
Sample Output 2
10+5i
-5i
25+25i

*/

struct  ComplexNumber
{
	int real, imaginer;
};

ComplexNumber addComplex(const ComplexNumber& z1, const ComplexNumber& z2)
{
	ComplexNumber newComplex;
	newComplex.real = z1.real + z2.real;
	newComplex.imaginer = z1.imaginer + z2.imaginer;
	return newComplex;
}

ComplexNumber substractComplex(const ComplexNumber& z1, const ComplexNumber& z2) {
	ComplexNumber newComplex;
	newComplex.real = z1.real - z2.real;
	newComplex.imaginer = z1.imaginer - z2.imaginer;
	return newComplex;
}

ComplexNumber multiplyComplex(const ComplexNumber& z1, const ComplexNumber& z2) {
	ComplexNumber newComplex;
	newComplex.real = (z1.real * z2.real) - (z1.imaginer * z2.imaginer);
	newComplex.imaginer = (z1.real * z2.imaginer) + (z1.imaginer * z2.real);
	return newComplex;
}


void print(const ComplexNumber& z1) {
	if (z1.real == 0 && z1.imaginer == 0) {
		std::cout << "0" << "\n";
		return;
	}
	else if (z1.real == 0) {
		std::cout << z1.imaginer << "i" << "\n";
		return;
	}
	else if (z1.imaginer == 0) {
		std::cout << z1.real << "\n";
		return;
	}
	else {
		std::cout << z1.real << (z1.imaginer > 0 ? "+" : "") << z1.imaginer << "i " << "\n";
		return;
	}
}

int main() {
	ComplexNumber z1, z2;
	std::cin >> z1.real >> z1.imaginer;
	std::cin >> z2.real >> z2.imaginer;
	ComplexNumber z3 = addComplex(z1, z2);
	ComplexNumber z4 = substractComplex(z1, z2);
	ComplexNumber z5 = multiplyComplex(z1, z2);
	
	std::cout << "Add: ";
	print(z3);
	std::cout << "\n";

	std::cout << "Substract: ";
	print(z4);
	std::cout << "\n";

	std::cout << "Multiply: ";
	print(z5);
	std::cout << "\n";

}