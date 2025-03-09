#include <iostream>

struct Complex{
    int real, imag;
};

Complex add(Complex const a, Complex const b){

    Complex result;

    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;

    return result;

}

Complex subtract(Complex const a, Complex const b){

    Complex result;

    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;

    return result;

}

Complex multiply(Complex const a, Complex const b){

    Complex result;

    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + b.real * a.imag;

    return result;

}

void print(Complex const a){

    if(a.real) std::cout << a.real;
    if(a.imag > 0) std::cout << '+';
    if(a.imag != 0) std::cout << a.imag << 'i';
    std::cout << '\n';

}

int main(){

    Complex a, b;

    std::cin >> a.real >> a.imag >> b.real >> b.imag;

    print(add(a, b));
    print(subtract(a, b));
    print(multiply(a, b));

    return 0;

}