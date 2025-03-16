#include <iostream>
#include <cmath>

struct QuadPoly {
	float a, b, c;

	// tuple е stl-ска структура, която е забранена за употреба освен, ако не е упоменато в условието изрично, че можете.
	std::tuple<float, float> solve() {
		// Използвай само английски символи в кода си, защото някои компилатори не разчитат други и е възможно човекът,
		// който ти проверява работата на контролно/изпит да не му тръгне и да ти ореже точките.
		float Δ = b*b - 4*a*c;

		if(Δ < 0) return std::make_tuple(NAN, NAN);
		if(Δ == 0) return std::make_tuple(-b/(2*a), NAN);

		float x1 = (-b + sqrt(Δ))/(2*a);
		float x2 = (-b - sqrt(Δ))/(2*a);
		if(x1 > x2) std::swap(x1, x2);
		return std::make_tuple(x1, x2);
	}
};

// Това е материал, който предстои да вземем, така че се въздържаме от употребата му, докато не стигнем до там.
std::istream &operator>>(std::istream &is, QuadPoly &p) {
	is >> p.a >> p.b >> p.c;
	return is;
}

int main() {
	QuadPoly p;
	std::cin >> p;

	float x1, x2;
	// Това преобразуване между типове също не би се харесало на никой от екипа!
	std::tie(x1, x2) = p.solve();

	if(std::isnan(x1)) std::cout << "The equation does not have real solutions!" << std::endl;
	else if(std::isnan(x2)) std::cout << "x1 = x2 = " << x1 << std::endl;
	else std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;

	return 0;
}

