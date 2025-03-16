#include <iostream>

// Същата забележка и тук!
struct Complex {
    int real;
    int imag;

    Complex add(const Complex& other) {
        return { real + other.real, imag + other.imag };
    }

    Complex subtract(const Complex& other) {
        return { real - other.real, imag - other.imag };
    }

    Complex multiply(const Complex& other) {
        int newReal = real * other.real - imag * other.imag;
        int newImag = real * other.imag + imag * other.real;
        return { newReal, newImag };
    }

    void print() {
        if (real == 0 && imag != 0) {
            std::cout << imag << "i";
        }
        else if (imag == 0) {
            std::cout << real;
        }
        else {
            std::cout << real;
            if (imag > 0)
                std::cout << "+" << imag << "i";
            else
                std::cout << imag << "i";
        }
        std::cout << "\n";
    }
};

int main() {
    Complex z1, z2;
    std::cin >> z1.real >> z1.imag >> z2.real >> z2.imag;

    Complex sum = z1.add(z2);
    Complex diff = z1.subtract(z2);
    Complex prod = z1.multiply(z2);

    sum.print();
    diff.print();
    prod.print();

    return 0;
}
