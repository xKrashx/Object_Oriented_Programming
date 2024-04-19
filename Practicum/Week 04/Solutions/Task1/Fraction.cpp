#include <iostream>

#include "Fraction.hpp"

void Fraction::Init(long long numerator, long long denominator)
{
    if(denominator == 0)
    {
        std::cout << "The denominator cannot be zero!" << std::endl;
        return;
    }
    
    this->numerator = numerator;
    this->denominator = denominator;
    this->Reduce();
}

long long Fraction::GetNumerator() const
{
    return this->numerator;
}

long long Fraction::GetDenominator() const
{
    return this->denominator;
}

void Fraction::SetNumerator(long long numerator)
{
    this->numerator = numerator;
    this->Reduce();
}

void Fraction::SetDenominator(long long denominator)
{
    if(denominator == 0)
    {
        std::cout << "The denominator cannot be zero!" << std::endl;
        return;
    }

    this->denominator = denominator;
    this->Reduce();
}

void Fraction::Add(const Fraction& other)
{
    this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
    this->denominator *= other.denominator;
    this->Reduce();
}

void Fraction::Subtract(const Fraction& other)
{
    this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
    this->denominator *= other.denominator;
    this->Reduce();
}

void Fraction::Mult(const Fraction& other)
{
    this->numerator *= other.numerator;
    this->denominator *= other.denominator;
    this->Reduce();
}

void Fraction::Divide(const Fraction& other)
{
    this->numerator *= other.denominator;
    this->denominator *= other.numerator;
    this->Reduce();
}

bool Fraction::IsEqual(const Fraction& other) const
{
    return this->numerator == other.numerator && this->denominator == other.denominator;
}

bool Fraction::IsLessThan(const Fraction& other) const
{
    return this->numerator * other.denominator < other.numerator * this->denominator;
}

void Fraction::Reverse()
{
    if(this->numerator == 0)
    {
        std::cout << "The denominator cannot be zero!" << std::endl;
        return;
    }
    
    long long temp = this->numerator;
    this->numerator = this->denominator;
    this->denominator = temp;
    this->Reduce();
}

double Fraction::Value() const
{
    return (double) this->numerator / this->denominator;
}

void Fraction::Print() const
{
    std::cout << this->numerator << '/' << this->denominator;
}

void Fraction::Reduce()
{
    unsigned int g = GCD(std::abs(this->numerator), std::abs(this->denominator));

    this->numerator /= g;
    this->denominator /= g;

    if(this->denominator < 0) 
    {
        this->numerator = -this->numerator;
        this->denominator = -this->denominator;
    }
}

long long Fraction::GCD(long long numerator, long long denominator)
{
    if(numerator == 0) 
    {
        return denominator;
    } 

    if(denominator == 0) 
    {
        return numerator;
    } 

    if(numerator == denominator) 
    {
        return numerator; 
    }

    if(numerator > denominator) 
    {
        return GCD(numerator - denominator, denominator);
    } 

    return GCD(numerator, denominator - numerator); 
}
