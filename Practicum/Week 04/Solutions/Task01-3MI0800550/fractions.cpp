#include "Fractions.h"

Fraction::Fraction()
{
    this->numerator = 1;
    this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator)
{
    if (denominator != 0)
    {

        this->numerator = numerator;
        this->denominator = denominator;
    }
    else
        std::cout << "Denom must !be 0" << std::endl;
        return;
}

void Fraction::setNumerator(int numerator)
{
    this->numerator = numerator;
};

void Fraction::setDenominator(int denominator)
{
    this->denominator = denominator;
};

int GCD(int a, int b)
{
    if (a == 0)
        return b;
    return GCD(b % a, a);
}

int LCM(int a, int b)
{
    return (a / GCD(a, b)) * b;
}

double Fraction::value()
{
    return (double)numerator / denominator;
};

void Fraction::operator+(Fraction other)
{

    int lcm = LCM(this->denominator, other.denominator);
    this->numerator *= lcm / this->denominator;
    other.numerator *= lcm / other.denominator;

    this->numerator = this->numerator + other.numerator;
    this->denominator = lcm;
}

void Fraction::operator<<(Fraction &huh)
{
    std::cout << huh.numerator << "/" << huh.denominator << std::endl;
};

void Fraction::add(Fraction other)
{

    int lcm = LCM(this->denominator, other.denominator);
    this->numerator *= lcm / this->denominator;
    other.numerator *= lcm / other.denominator;

    this->numerator = this->numerator + other.numerator;
    this->denominator = lcm;
};

void Fraction::subtract(Fraction other)
{
    int lcm = LCM(this->denominator, other.denominator);
    this->numerator *= lcm / this->denominator;
    other.numerator *= lcm / other.denominator;

    this->numerator = this->numerator - other.numerator;
    this->denominator = lcm;
}

void Fraction::divide(Fraction other)
{
    this->numerator *= other.denominator;
    this->denominator *= other.numerator;
};

void Fraction::mult(Fraction other)
{
    this->numerator *= other.numerator;
    this->denominator *= other.denominator;
};

void Fraction::reverse()
{
    int temp = this->numerator;
    this->numerator = this->denominator;
    this->denominator = temp;
};

bool Fraction::compare(Fraction other)
{
    int lcm = LCM(this->denominator, other.denominator);
    this->numerator *= lcm / this->denominator;
    other.numerator *= lcm / other.denominator;

    if (this->numerator > other.numerator)
        return this;
    else
        return false;
};

void Fraction::print() // Принтира дробта с дробна черта в конзолата
{
    reduce();
    if (this->denominator == 1)
        std::cout << this->numerator << std::endl;
    else
        std::cout << this->numerator << "/" << this->denominator << std::endl;
};

void Fraction::reduce()
{
    int gcd = GCD(this->numerator, this->denominator);

    this->numerator /= gcd;
    this->denominator /= gcd;
};