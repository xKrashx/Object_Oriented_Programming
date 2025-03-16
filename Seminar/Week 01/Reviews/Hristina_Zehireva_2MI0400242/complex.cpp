#include <iostream>


struct Complex
{
    int real;
    int imag;

    // За методи не е говорено, така че нека не бързаме с материала!
    Complex add(const Complex& other) const{
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.real;
        return result;
    }

    Complex substract(const Complex  &other) const{
        Complex result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }

    Complex multiply(const Complex  &other) const{
        Complex result;
        result.real = real * other.real - imag * other.imag;
        result.imag = real * other.imag + imag * other.real;
        return result;
    }

    void print() const{
        if (imag >= 0)
            std::cout << real << "+" << imag << "i" << '\n';
        else
            std::cout << real << imag << "i" << '\n';
        
    }

};

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (a < -1000 || a > 1000 || b < -1000 || b > 1000 || c < -1000 || c > 1000)
    {
        std::cerr << "error";
        return 1;
    }
    

    Complex z1;
    z1.real = a;
    z1.imag = b;

    Complex z2;
    z2.real = c;
    z2.imag = d;

    Complex sum = z1.add(z2);
    Complex difference = z1.substract(z2);
    Complex product = z1.multiply(z2);

    sum.print();
    difference.print();
    product.print();

    return 0;
}