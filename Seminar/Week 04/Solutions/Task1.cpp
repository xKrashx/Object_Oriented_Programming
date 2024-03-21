#include <iostream>

class Complex{

    public:
        int getReal() const;
        int getImag() const;

        void setReal(const int &);
        void setImag(const int &);

        void print() const;
        
    private:
        int real, imag;

};


int Complex::getReal() const{
    return real;
}

int Complex::getImag() const{
    return imag;
}

void Complex::setReal(const int &real){
    this -> real = real;
}

void Complex::setImag(const int &imag){
    this -> imag = imag;
}

void Complex::print() const{

    if(real) std::cout << real;
    if(imag > 0) std::cout << '+';
    if(imag) std::cout << imag << 'i';
    std::cout << '\n';

}


Complex add(const Complex &l, const Complex &r){

    Complex newComplex;

    newComplex.setReal(l.getReal() + r.getReal());
    newComplex.setImag(l.getImag() + r.getImag());

    return newComplex;

}

Complex subtract(const Complex &l, const Complex &r){

    Complex newComplex;

    newComplex.setReal(l.getReal() - r.getReal());
    newComplex.setImag(l.getImag() - r.getImag());

    return newComplex;

}

Complex multiply(const Complex &l, const Complex &r){

    Complex newComplex;

    newComplex.setReal(l.getReal() * r.getReal() - l.getImag() * r.getImag());
    newComplex.setImag(l.getReal() * r.getImag() + l.getImag() * r.getReal());

    return newComplex;

}

int main(){

    Complex a, b;
    int real, imag;

    std::cin >> real >> imag;
    a.setReal(real);
    a.setImag(imag);

    std::cin >> real >> imag;
    b.setReal(real);
    b.setImag(imag);

    a.print();
    b.print();

    Complex addition = add(a, b);
    Complex subtraction = subtract(a, b);
    Complex multiplication = multiply(a, b);

    addition.print();
    subtraction.print();
    multiplication.print();

    return 0;

}