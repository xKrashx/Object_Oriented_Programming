#include <iostream>
#include <cmath>

// Лоша практика!
using namespace std;


struct ComplexNum {
    double real;
    double imag;

    void print() const{
        if (imag >= 0)
        {
            // Защо на едно място го пишеш с std:: на друго без.
            // Изглежда неконсистентно и объркващо на моменти.
            std::cout << real << " + " << imag << "i" << endl;          
        }
        else 
        {
            std::cout << real << " - " << imag << "i" << endl;
        }
    }
};

ComplexNum multiply(const ComplexNum& a, const ComplexNum& b) {
    return {a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

ComplexNum addition(const ComplexNum& a, const ComplexNum& b) {
    return {a.real + b.real, a.imag + b.imag};
}

ComplexNum substract(const ComplexNum& a, const ComplexNum& b) {
    return {a.real - b.real, a.imag - b.imag};
}

ComplexNum read() {
    ComplexNum number;
    std::cin >> number.real;
    std::cin >> number.imag;
    return number;
}

int main() {
   ComplexNum number1 = read();
   ComplexNum number2 = read();

   ComplexNum sum = addition(number1, number2);
   sum.print();
   
   ComplexNum difference = substract(number1, number2);
   difference.print();

   ComplexNum product = multiply(number1, number2);
   product.print();

   return 0;
}