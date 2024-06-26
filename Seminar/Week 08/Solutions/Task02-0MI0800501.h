#pragma once
#include <iostream>
class Complex {
public:
	Complex(); //Default constructor
	Complex(double real, double img); //Parametrized constructor
	Complex(Complex& other); //Copy constructor
	Complex& operator =(const Complex& other);
	Complex& operator +=(const Complex& other);
	Complex operator +(const Complex& other);
	Complex& operator -=(const Complex& other);
	Complex operator -(const Complex& other);
	Complex operator *(const Complex& other);
	Complex& operator *=(const Complex& other);
	Complex operator /(const Complex& other);
	Complex& operator /=(const Complex& other);

	friend std::ostream& operator <<(std::ostream& out, const Complex& obj);
	friend std::istream& operator >>(std::istream& in,  Complex& obj);

	void Copy(const Complex& other);
	double getmodul()const;
	double getimg()const;
	double getreal()const;
private:
	double myreal;
	double myimg;
};
