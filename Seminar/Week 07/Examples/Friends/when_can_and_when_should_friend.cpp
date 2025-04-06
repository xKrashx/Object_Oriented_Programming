#include <iostream>

using std::cin;
using std::cout;

// За + оператор приемаме, че добавяме само реална част
class Complex{

    public:
        Complex() = default;
        Complex(int const real, int const imag): real(real), imag(imag){}

        // Имплементирани за олеснение.
        Complex &operator +=(Complex const &);
        Complex &operator +=(int const);
        
        // Тези разновидности на операторите, където първият аргумент е от класът,
        // можем да дефинираме, както вътре в класа, така и като friend.
        Complex operator +(Complex const &);
        friend Complex operator +(Complex const &, Complex const &);
        Complex operator +(int const);
        friend Complex operator +(Complex const &, int const);

        // Тези оператори, чиито първи аргумент не е от класът, 'ТРЯБВА' да е friend.
        friend Complex operator +(int const, Complex const &);

    private:
        int real, imag;

};

Complex &Complex::operator +=(Complex const &other){

    real += other.real;
    imag += other.imag;

    return *this;

}

Complex &Complex::operator +=(int const real){

    this -> real += real;
    return *this;

}

Complex Complex::operator +(Complex const &other){

    cout << "Inside class operator + for two complex\n";
    Complex result(*this);
    result += other;
    return result;

}

Complex Complex::operator +(int const real){

    cout << "Inside class operator + for complex and real\n";
    Complex result(*this);
    result += real;
    return result;

}

Complex operator +(Complex const &lhs, Complex const &rhs){

    cout << "Inside friend operator + for two complex\n";
    Complex result(lhs);
    result += rhs;
    return result;

}

Complex operator +(Complex const &lhs, int const rhs){

    cout << "Inside friend operator + for complex and real\n";
    Complex result(lhs);
    result += rhs;
    return result;

}

Complex operator +(int const lhs, Complex const & rhs){

    cout << "Inside friend operator + for real and complex\n";
    Complex result(rhs);
    result += lhs;
    return result;

}

int main(){

    Complex c(5, 3);
    Complex c1 = c + 2; // in class
    Complex c2, c3;

    c1 = operator +(c, 2); // friend
    c2 = c1 + c; // in class

    c3 = c1.operator +(c2); // in class
    c3 = operator +(c1, c2); // friend

    c2 = 3 + c1; // friend

}