#ifndef __FRACTION_HPP
#define __FRACTION_HPP

class Fraction
{
    public:
        void Init(long long numerator, long long denominator);

        long long GetNumerator() const;
        long long GetDenominator() const;

        void SetNumerator(long long numerator);
        void SetDenominator(long long denominator);

        void Add(const Fraction& other);
        void Subtract(const Fraction& other);
        void Mult(const Fraction& other);
        void Divide(const Fraction& other);

        bool IsEqual(const Fraction& other) const;
        bool IsLessThan(const Fraction& other) const;

        void Reverse();
        
        double Value() const;
        void Print() const;

    private:
        long long numerator = 0;
        long long denominator = 1;

        void Reduce();
        long long GCD(long long numerator, long long denominator);
};

#endif
