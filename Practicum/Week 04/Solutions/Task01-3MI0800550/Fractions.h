#pragma once
#include <iostream>

class Fraction
{
private: 
    int numerator;
    int denominator;
    void reduce();

public:
    Fraction();
    Fraction(int numerator, int denominator);
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    double value();
    void operator+(Fraction other);
    void operator<<(Fraction &huh);
    void add(Fraction other);
    void subtract(Fraction other);
    void divide(Fraction other);
    void mult(Fraction other);
    void reverse();
    bool compare(Fraction other);
    void print(); // Принтира дробта с дробна черта в конзолата
};
