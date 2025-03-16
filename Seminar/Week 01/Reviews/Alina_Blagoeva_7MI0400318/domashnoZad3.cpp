#include <iostream>

struct ComplexNumber {
    int a; 
    int b;
};

ComplexNumber addComplex(ComplexNumber num1,ComplexNumber num2) {
    int realPart = num1.a + num2.a;
    int imaginaryPart = num1.b + num2.b;
    
    return ComplexNumber{ realPart, imaginaryPart };
}

ComplexNumber subtractComplex(ComplexNumber num1, ComplexNumber num2) {
    int realPart = num1.a - num2.a;
    int imaginaryPart = num1.b - num2.b;

    return ComplexNumber{ realPart, imaginaryPart };
}


ComplexNumber multiplyComplex(ComplexNumber num1, ComplexNumber num2) {
    int a = num1.a, b = num1.b;
    int c = num2.a, d = num2.b;

    int realPart = a*c - b*d;
    int imaginaryPart = a*d + b*c;

    return ComplexNumber{ realPart, imaginaryPart };
}


void printComplex(ComplexNumber num) {
    int a = num.a, b = num.b;


    if (b > 0 && a != 0) {
        std::cout << num.a << "+" << num.b << "i" << std::endl;
    }
    else if (b < 0 && a != 0) {
        std::cout << num.a << num.b << "i" << std::endl;
    }
    else if (b == 0 && a != 0) {
        std::cout << num.a << std::endl;
    } 
    else if (b != 0 && a == 0) {
        std::cout << num.b << "i" << std::endl;
    }
    else {
        std::cout << num.a << "+" << num.b << "i" << std::endl;
    }
}

//to do create input function for complex numbers
int main()
{
    ComplexNumber num1 = {6, -4 };
    ComplexNumber num2 = { 10, 7 };

    printComplex(addComplex(num1,num2));
    printComplex(subtractComplex(num1, num2));
    printComplex(multiplyComplex(ComplexNumber{0,0},num2));

}
