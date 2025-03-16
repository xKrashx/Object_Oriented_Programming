#include <iostream>

struct Complex {
    int real, imag;
};

Complex add(const Complex& z1, const Complex& z2) {
    return { z1.real + z2.real, z1.imag + z2.imag };
}

Complex subtract(const Complex& z1, const Complex& z2) {
    return { z1.real - z2.real, z1.imag - z2.imag };
}

Complex multiply(const Complex& z1, const Complex& z2) {
    return {
        z1.real * z2.real - z1.imag * z2.imag,
        z1.real * z2.imag + z1.imag * z2.real
    };
}

void printComplex(const Complex& z) {
    if (z.imag == 0) {
        std::cout << z.real << std::endl;
    }
    else if (z.real == 0) {
        std::cout << z.imag << "i" << std::endl;
    }
    else {
        std::cout << z.real;
        if (z.imag > 0) {
            std::cout << "+" << z.imag << "i" << std::endl;
        }
        else {
            std::cout << z.imag << "i" << std::endl;
        }
    }
}

int main() {
    Complex z1, z2;
    std::cin >> z1.real >> z1.imag >> z2.real >> z2.imag;

    printComplex(add(z1, z2));
    printComplex(subtract(z1, z2));
    printComplex(multiply(z1, z2));

    return 0;
}
