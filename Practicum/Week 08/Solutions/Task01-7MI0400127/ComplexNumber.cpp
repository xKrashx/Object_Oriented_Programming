#include "ComplexNumber.hpp"

#include <cmath>

ComplexNumber::ComplexNumber() : real(0), imag(0) {};
ComplexNumber::ComplexNumber(double real, double imag) : real(real), imag(imag) {};
ComplexNumber::ComplexNumber(const ComplexNumber& other) : real(other.real), imag(other.imag) {};
ComplexNumber::~ComplexNumber() {};

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other)
{
    if (this != &other)
    {
        this->real = other.real;
        this->imag = other.imag;
    }
    return *this;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other)
{
    this->real += other.real;
    this->imag += other.imag;
}

ComplexNumber& ComplexNumber::operator+=(double number)
{
    this->real += number;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other)
{
    this->real -= other.real;
    this->imag -= other.imag;
}

bool ComplexNumber::operator==(const ComplexNumber& other)
{
    return (this->real == other.real) && (this->imag == other.imag);
}

bool ComplexNumber::operator!=(const ComplexNumber& other)
{
    return !(*this == other);
}

double ComplexNumber::getReal() const
{
    return this->real;
}

double ComplexNumber::getImag() const
{
    return this->imag;
}

void ComplexNumber::setReal(double real)
{
    this->real = real;
}

void ComplexNumber::setImag(double imag)
{
    this->imag = imag;
}

double ComplexNumber::AbsComplex() const
{
    return sqrt(pow(this->real, 2) + pow(this->imag, 2));
}

ComplexNumber ComplexNumber::ComplexConjugate() const
{
    ComplexNumber temp(*this);
    temp.setImag(temp.getImag() * -1);
    return temp;
}

ComplexNumber operator+(const ComplexNumber& first, const ComplexNumber& second)
{
    ComplexNumber temp(first);
    temp += second;
    return temp;
}

ComplexNumber operator+(const ComplexNumber& first, double number)
{
    ComplexNumber temp(first);
    temp += number;
    return temp;
}

ComplexNumber operator-(const ComplexNumber& first, const ComplexNumber& second)
{
    ComplexNumber temp(first);
    temp -= second;
    return temp;
}

ComplexNumber operator*(const ComplexNumber& first, const ComplexNumber& second)
{
    ComplexNumber temp(first);
    double newReal = first.getReal() * second.getReal() - first.getImag() * second.getImag();
    double newImag = first.getReal() * second.getImag() + first.getImag() * second.getReal();
    temp.setReal(newReal);
    temp.setImag(newImag);
    return temp;
}

ComplexNumber operator*(const ComplexNumber& first, double number)
{
    ComplexNumber temp(first);
    temp.setReal(first.getReal() * number);
    temp.setImag(first.getImag() * number);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& obj)
{
    os << "(" << obj.getReal() << "," << obj.getImag() << ")";
    return os;
}

std::istream& operator>>(std::istream& is, ComplexNumber& obj)
{
    double real, imag;
    is >> real;
    is >> imag;
    obj.setReal(real);
    obj.setImag(imag);
    return is;
}