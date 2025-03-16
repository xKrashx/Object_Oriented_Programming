// Идеално разписана задача
#include <iostream>
#include <cmath>
/*
������ 2: ������������ ���������, ����� �������� ��������� ���������. ����������� ��������� �� �������� � 3 ����������� a, b, c,
����� �� ���������� ������ �����. �������� ������ �� ���������� �� ��������� ��� ��� ������ ������.

Input Format
�� ������� ��� �� �������� 3 ������ ����� a, b � c.

Constraints
-100 <= a, b, c <= 100
Output Format
�� ���� ��� �� ������������ �����, �� �� ������ ���� �� �������� ��� ����, � ���������� �� ��������� �� ����������� ���������: -
���� ������ -> "The equation does not have real solutions!" - ��� 2 ������� ������ -> x1 = x2 = "{�����}" - ��� 2 �������� ������ -> x1 = "{����� 1}"
, x2 = "{����� 2}" � ���������� ������ ���� x1 < x2.

Sample Input 0
1 -3 2
Sample Output 0
x1 = 1, x2 = 2
Explanation 0
��� ����� ����������� ���������� x^2-3x+2=0 � ���������� �������� 1 � 2.

Sample Input 1
-60 -3 -59
Sample Output 1
The equation does not have real solutions!

Sample Input 2
1 4 4
Sample Output 2
x1 = x2 = -2
*/

struct Equation
{
	double x, y, z;

	void solve()const {
		if (x == 0) {
			std::cout << "Equation does not have real solutions!" << std::endl;
			return;
		}
		double discriminant = (pow(y, 2) - 4*x*z);
		if (discriminant < 0) {
			std::cout << "The equation does not have real solutions!" << std::endl;
			return;
		}
		else if (discriminant == 0) {
			int result = (- y + sqrt(discriminant)) / 2 * x;
			std::cout << "The equation has two identical roots -> x1 = x2 = {" << result << "}" << std::endl;
			return;
		}
		else {
			int  x1 = (- y - sqrt(discriminant)) / 2 * x;
			int x2 = (- y + sqrt(discriminant)) / 2 * x;
			std::cout << "The equation has two roots -> x1 = {" << x1 << "} and x2 = {" << x2 << "}" << std::endl;
			return;
		}
	}

};

int main() {
	Equation eq;
	std::cin >> eq.x >> eq.y >> eq.z;
	eq.solve();

	return 0;
}