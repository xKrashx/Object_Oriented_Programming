#include "ComplexNumber.hpp"

#include <cmath>

ComplexNumber::ComplexNumber() : ComplexNumber(0, 0)
{ }

ComplexNumber::ComplexNumber(double re, double im) : re(re), im(im)
{ }

double ComplexNumber::GetRe() const
{
    return this->re;
}

double ComplexNumber::GetIm() const
{
    return this->im;
}

void ComplexNumber::SetRe(double re)
{
    this->re = re;
}

void ComplexNumber::SetIm(double im)
{
    this->im = im;
}

double ComplexNumber::AbsComplex() const
{
    return sqrt(this->re * this->re + this->im * this->im);
}

bool ComplexNumber::operator!() const
{
    const double EPS = 0.00001;
    return std::abs(this->re) < EPS && std::abs(this->im) < EPS;
}

ComplexNumber ComplexNumber::ComplexConjugate() const
{
    return ComplexNumber(this->re, -this->im);
}

ComplexNumber& ComplexNumber::operator += (const ComplexNumber& other)
{
    this->re += other.re;
    this->im += other.im;
    return *this;
}

ComplexNumber& ComplexNumber::operator += (double num)
{
    return *this += ComplexNumber(num, 0);
}

ComplexNumber& ComplexNumber::operator -= (const ComplexNumber& other)
{
    this->re -= other.re;
    this->im -= other.im;
    return *this;
}

ComplexNumber& ComplexNumber::operator *= (const ComplexNumber& other)
{
    double temp = this->re * other.re - this->im * other.im;
    this->im = this->re * other.im + this->im * other.re;
    this->re = temp;
    return *this;
}

ComplexNumber& ComplexNumber::operator *= (double num)
{
    this->re *= num;
    this->im *= num;
    return *this;
}

bool ComplexNumber::operator == (const ComplexNumber& other) const
{
    return this->re == other.re && this->im == other.im;
}

bool ComplexNumber::operator != (const ComplexNumber& other) const
{
    return !(*this == other);
}

std::istream& operator >> (std::istream& in, ComplexNumber& c)
{
    if(in.fail() || in.bad()) return in;

    in.get(); // removes '('
    in >> c.re;
    in.get(); // removes ','
    in >> c.im;
    in.get(); // removes ')'

    return in;
}

std::ostream& operator << (std::ostream& out, const ComplexNumber& c)
{
    if(out.fail() || out.bad()) return out;
    
    out << '(' << c.re << ',' << c.im << ')';
    return out;
}

ComplexNumber operator + (const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber result(c1);
    return result += c2;
}

ComplexNumber operator + (const ComplexNumber& c, double num)
{
    ComplexNumber result(c);
    return result += num;
}

ComplexNumber operator + (double num, const ComplexNumber& c)
{
    return c + num;
}

ComplexNumber operator - (const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber result(c1);
    return result -= c2;
}

ComplexNumber operator * (const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber result(c1);
    return result *= c2;
}

ComplexNumber operator * (const ComplexNumber& c, double num)
{
    ComplexNumber result(c);
    return result *= num;
}

ComplexNumber operator * (double num, const ComplexNumber& c)
{
    return c * num;
}
