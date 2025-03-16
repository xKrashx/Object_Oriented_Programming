// Същите забележки както на първа задача.
#include <iostream>
#include <iomanip>

using namespace std;

struct ComplexNumber {
    int real, imag;

    ComplexNumber(int real, int imag) : real(real), imag(imag) {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    void print() const {
        if (imag >= 0)
            cout << real << "+" << imag << "i";
        else
            cout << real << "" << imag << "i";
    }
};

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    ComplexNumber z1(a, b), z2(c, d);

    ComplexNumber sum = z1 + z2;
    ComplexNumber diff = z1 - z2;
    ComplexNumber prod = z1 * z2;

    sum.print();
    cout << endl;
    diff.print();
    cout << endl;
    prod.print();
    cout << endl;

    return 0;
}
