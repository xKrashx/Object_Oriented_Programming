#include <iostream>

struct Complex {
	int a, b;

	// Отново за оператори е предвидено да се говори, така че до тогава гледаме да не ги ползваме.
	Complex operator+(Complex const &n) {
		return { a + n.a, b + n.b };
	}

	Complex operator-(Complex const &n) {
		return { a - n.a, b - n.b };
	}

	Complex operator*(Complex const &n) {
		return { a*n.a - b*n.b, a*n.b + b*n.a };
	}
};

std::istream &operator>>(std::istream &is, Complex &n) {
	is >> n.a >> n.b;
	return is;
}

std::ostream &operator<<(std::ostream &os, const Complex &n) {
	if(n.a != 0) os << n.a;
	if(n.b != 0) os << std::showpos << n.b << "i" << std::noshowpos;
	if(n.a == 0 && n.b == 0) os << 0;
	return os;
}

int main() {
	Complex x, y;
	std::cin >> x >> y;
	std::cout
		<< x + y << std::endl
		<< x - y << std::endl
		<< x * y << std::endl;

	return 0;
}

