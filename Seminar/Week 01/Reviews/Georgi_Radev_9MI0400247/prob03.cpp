#include <iostream>
#include <cmath>

// Защо?
const double EPS = 1e-9;

struct Complex {
	double re;
	double im;
};

Complex plus(Complex a, Complex b);
Complex minus(Complex a, Complex b);
Complex mult(Complex a, Complex b);

int main() {
	// Липсва каквато и да е логика
	return 0;
}

Complex plus(Complex a, Complex b) {
	Complex r;
	r.re = a.re + b.re;
	r.im = a.im + b.im;
	return r;
}
Complex minus(Complex a, Complex b) {
	Complex r;
	r.re = a.re - b.re;
	r.im = a.im - b.im;
	return r;
}
Complex mult(Complex a, Complex b) {
	Complex r;
	r.re = a.re*b.re - a.im*b.im;
	r.im = a.re*b.im + b.im*a.re;
	return r;
}

double mod(double a) {
	return a < 0 ? -a : a;
}