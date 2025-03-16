#include <iostream>

// Лоша практика!
using namespace std;

struct ComplexNumber {

    int real, imaginery;

    ComplexNumber(int r, int i) : real(r), imaginery(i) {}

    ComplexNumber operator+(const ComplexNumber& other) {

        return ComplexNumber(real + other.real, imaginery + other.imaginery);
    }

    ComplexNumber operator-(const ComplexNumber& other) {

        return ComplexNumber(real - other.real, imaginery - other.imaginery);
    }

    ComplexNumber operator*(const ComplexNumber& other) {

        return ComplexNumber(real * other.real - imaginery * other.imaginery, real * other.imaginery + imaginery * other.real);
    }

    void print() {

        if (imaginery == 0) {

            cout << real << endl;
        }
        else if (imaginery > 0) {

            cout << real << "+" << imaginery << "i" << endl;
        }
        else {

            cout << real << imaginery << "i" << endl;
        }
    }
};

int main() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < -1000 || a > 1000 || b < -1000 || b > 1000 ||
        c < -1000 || c > 1000 || d < -1000 || d > 1000) {

        cerr << "Error. Values must be: [-1000, 1000]." << endl;
        return 1;
    }

    ComplexNumber z1(a, b), z2(c, d);

    (z1 + z2).print();
    (z1 - z2).print();
    (z1 * z2).print();

    return 0;
}
