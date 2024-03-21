#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Селектори и мутатори
    int getNumerator() const;
    void setNumerator(int num);
    int getDenominator() const;
    void setDenominator(int denom);

    // Други методи
    double value() const;
    void add(const Fraction &other);
    void subtract(const Fraction &other);
    void divide(const Fraction &other);
    void mult(const Fraction &other);
    void reverse();
    bool compare(const Fraction &other) const;
    void print() const;
    void reduce();

private:
    int findGCD(int a, int b) const;
};

#endif // FRACTION_H