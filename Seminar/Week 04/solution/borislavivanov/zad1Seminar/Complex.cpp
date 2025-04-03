#include "complex.hpp"
#include <iostream>

    Complex::Complex(){
        
    }
    Complex::Complex(const double re,const double im){
        this->Im = im;
        this->Re = re;
        
    }
    double Complex::getRe()const{return Re;}
    
    void Complex::setRe(const double Re){this->Re = Re;}
    
    double Complex::getIm() const {return Im;}

    void Complex::setIm(const double Im){this->Im = Im;}

    void Complex::print()const {std::cout<<'('<<Re<<','<<Im<<")";}

    Complex & Complex::operator= (const Complex c){
        this->Im = c.getIm();
        this->Re = c.getRe();
        return *this;
    }
    Complex Complex::operator+ (const Complex c) const{
        Complex result;
        result.setIm(this->Im+c.getIm());
        result.setRe(this->Re+c.getRe());
        return result;
    }
    Complex Complex::operator- (const Complex c) const{
        Complex result;
        result.setIm(this->Im-c.getIm());
        result.setRe(this->Re-c.getRe());
        return result;
    }

    Complex Complex::operator* (const Complex c)const{
        Complex result;
        result.setIm((this->Re*c.getIm())+(this->Im*c.getRe()));
        result.setRe((this->Re*c.getRe())-(this->Im*c.getIm()));
        return result;
    }

