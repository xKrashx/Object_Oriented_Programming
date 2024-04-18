#ifndef __COMPLEX_NUMBER
#define __COMPLEX_NUMBER

#include <fstream>

class ComplexNumber
{
    public:
    ComplexNumber();
    ComplexNumber(double real, double imag);
    ComplexNumber(const ComplexNumber& other);

    ~ComplexNumber();

    ComplexNumber& operator=(const ComplexNumber& other);
    ComplexNumber& operator+=(const ComplexNumber& other);
    ComplexNumber& operator+=(double number);
    ComplexNumber& operator-=(const ComplexNumber& other);
    bool operator==(const ComplexNumber& other);
    bool operator!=(const ComplexNumber& other);

    double getReal() const;
    double getImag() const;

    void setReal(double real);
    void setImag(double imag);

    double AbsComplex() const;
    ComplexNumber ComplexConjugate() const;

    private:
    double real;
    double imag;
};

ComplexNumber operator+(const ComplexNumber& first, const ComplexNumber& second);
ComplexNumber operator+(const ComplexNumber& first, double number);

ComplexNumber operator-(const ComplexNumber& first, const ComplexNumber& second);

ComplexNumber operator*(const ComplexNumber& first, const ComplexNumber& second);
ComplexNumber operator*(const ComplexNumber& first, double number);

std::ostream& operator<<(std::ostream& os, const ComplexNumber& obj);
std::istream& operator>>(std::istream& is, ComplexNumber& obj);

#endif