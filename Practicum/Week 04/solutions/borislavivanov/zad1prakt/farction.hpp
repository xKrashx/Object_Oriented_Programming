#pragma once

class Fraction
{
    private:
    int num,denum;

    public:
    int getNum()const;
    int getDenum() const;
    void setNum(int num);
    void setDenum(int denum);
    double value() const;
    void add(const Fraction &other);
    void subtract(const Fraction &other);
    void divide(const Fraction &other);
    void mult(const Fraction &other);
    void reverse();
    bool compare(const Fraction &other)const;
    void print();
    void reduce();

};