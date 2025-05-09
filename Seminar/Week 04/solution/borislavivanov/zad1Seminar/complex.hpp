#pragma once
class Complex{
    private:

    double Re;
    double Im;

    public:
    Complex();
    Complex(const double re,const double im);
    
    double getRe()const;
    
    void setRe(const double Re);
    
    double getIm() const ;

    void setIm(const double Im);

    void print() const;

    Complex &operator=(const Complex c);
       
  
    Complex operator+ (const Complex c) const;
    Complex operator- (const Complex c) const;

    Complex operator* (const Complex c)const;

};