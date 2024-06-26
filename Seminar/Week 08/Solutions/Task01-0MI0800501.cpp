#include "ComplexNumber.h"
#include <iostream>
double Complex::getimg()const {
	return myimg;
}
double Complex::getreal()const {
	return myreal;
}
void Complex::Copy(const Complex& other){
	this->myreal = other.getreal();
	this->myimg = other.getimg();
}

double Complex::getmodul()const {
	return myimg * myimg + myreal * myreal;
}

Complex::Complex(Complex& other) {
	this->Copy(other);
 }
Complex::Complex(double real, double img) {
	this->myreal = real;
	this->myimg = img;
}
Complex::Complex() {
	this->myreal = 0.0;
	this->myimg = 0.0;
}
Complex& Complex::operator=(const Complex& other) {
	this->Copy(other);
	return *this;
}




Complex& Complex::operator+=(const Complex& other) {
	this->myreal += other.myreal;
	this->myimg += other.myimg;
	return *this;
}
Complex Complex::operator+(const Complex& other) {
	Complex result;
	result.myreal = other.myreal + this->myreal;
	result.myimg = other.myimg + this->myimg;
	return result;
}
Complex& Complex::operator-=(const Complex& other) {
	this->myreal -= other.myreal;
	this->myimg -= other.myimg;
	return *this;
}
Complex Complex::operator-(const Complex& other) {
	Complex result;
	result.myreal =this->myreal - other.myreal;
	result.myimg = this->myimg-other.myimg;
	return result;
}
Complex Complex::operator *(const Complex& other) {
	Complex result;
	result.myreal = this->myreal * other.myimg - this->myimg * other.myreal;
	result.myimg = this->myreal * other.myimg + this->myimg * other.myreal;
	return result;
}
Complex& Complex::operator*=(const Complex& other) {
	this->myreal = this->myreal * other.myimg - this->myimg * other.myreal;
	this->myimg= this->myreal * other.myimg + this->myimg * other.myreal;
	return *this;
}

Complex Complex::operator /(const Complex& other) {
	if (other.myimg == 0 && other.myreal == 0) {
		throw "Improper operation!";
	}
	Complex result;
	result.myreal = ((this->myreal*other.myreal)+(this->myimg*other.myimg))/other.getmodul();
	result.myimg = ((this->myimg*other.myreal)-(this->myreal*other.myimg))/other.getmodul();
	return result;
}
Complex& Complex::operator/=(const Complex& other) {
	if (other.myimg == 0 && other.myreal == 0) {
		throw "Improper operation!";
	}
	double temp_real = this->myreal;
	this->myreal = ((this->myreal * other.myreal) + (this->myimg * other.myimg)) / (other.getmodul());
	this->myimg = ((this->myimg * other.myreal) - (temp_real * other.myimg)) / (other.getmodul());
	return *this;
}
 std::ostream& operator <<(std::ostream& out, const Complex& obj) {
	 char sign='+';
	 if (obj.myimg < 0.0) {
		 sign = '-';
		 out << obj.myreal << " " << sign << " " << -obj.myimg << "*i";
		 return out;
	 }
	 out << obj.myreal << " " << sign << " " << obj.myimg << "*i";
	 return out;
}

 std::istream& operator >>(std::istream& in, Complex& obj) {
	 char plus;
	 char imag;
	 in >> obj.myreal >>plus>>obj.myimg>>imag;
	 if (plus != '+' || imag != 'i')
		 throw "invalid input!";
	 return in;
 }
