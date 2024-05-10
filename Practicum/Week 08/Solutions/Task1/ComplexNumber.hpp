#ifndef __COMPLEX_NUMBER_HPP
#define __COMPLEX_NUMBER_HPP

#include <iostream>

class ComplexNumber
{
    public:
        ComplexNumber();
        ComplexNumber(double re, double im);

        double GetRe() const;
        double GetIm() const;

        void SetRe(double re);
        void SetIm(double im);

        double AbsComplex() const;

        bool operator!() const;

        ComplexNumber ComplexConjugate() const;

        ComplexNumber& operator += (const ComplexNumber& other);
        ComplexNumber& operator += (double num);

        ComplexNumber& operator -= (const ComplexNumber& other);

        ComplexNumber& operator *= (const ComplexNumber& other);
        ComplexNumber& operator *= (double num);

        bool operator == (const ComplexNumber& other) const;
        bool operator != (const ComplexNumber& other) const;

        friend std::istream& operator >> (std::istream& in, ComplexNumber& c);
        friend std::ostream& operator << (std::ostream& out, const ComplexNumber& c);

    private:
        double re, im;
};

ComplexNumber operator + (const ComplexNumber& c1, const ComplexNumber& c2);
ComplexNumber operator + (const ComplexNumber& c, double num);
ComplexNumber operator + (double num, const ComplexNumber& c);

ComplexNumber operator - (const ComplexNumber& c1, const ComplexNumber& c2);

ComplexNumber operator * (const ComplexNumber& c1, const ComplexNumber& c2);
ComplexNumber operator * (const ComplexNumber& c, double num);
ComplexNumber operator * (double num, const ComplexNumber& c);

#endif
