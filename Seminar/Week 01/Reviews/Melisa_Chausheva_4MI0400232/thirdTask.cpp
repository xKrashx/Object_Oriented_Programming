#include <iostream>

// Защо със C синтаксис?
typedef struct 
{
    int real;
    int imag;
} Complex;

Complex add(Complex z1, Complex z2)
{
    Complex result;
    result.real = z1.real + z2.real;
    result.imag = z1.imag + z2.imag;
    return result;
}

Complex subtract(Complex z1, Complex z2) 
{
    Complex result;
    result.real = z1.real - z2.real;
    result.imag = z1.imag - z2.imag;
    return result;
}

Complex multiply(Complex z1, Complex z2) 
{
    Complex result;
    result.real = z1.real * z2.real - z1.imag * z2.imag; 
    result.imag = z1.real * z2.imag + z1.imag * z2.real; 
    return result;
}

void printComplex(Complex z)
{
    bool realPrinted = false, imagPrinted = false;

    if (z.real != 0)
    {
        std::cout << z.real;
        realPrinted = true;
    }

    if (z.imag != 0) 
    {
        if (realPrinted)
        {
            if (z.imag > 0)
            {
                std::cout << " + " << z.imag << "i";
            }
            else
            {
                std::cout << " - " << -z.imag << "i";
            }
        }
        else 
        {
            std::cout << z.imag << "i";
        }
    }
    else if (!realPrinted) 
    {
        std::cout << "0";
    }

    std::cout << std::endl;
}

int main()
{
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	if (a < -1000 || b < -1000 || c < -1000 ||
		a>1000 || b>1000 || c>1000)
	{
		std::cout << "Imvalid input!"<<std::endl;
		return 1;
	}

    Complex z1 = { a, b };
    Complex z2 = { c, d };

    Complex sum = add(z1, z2);
    Complex diff = subtract(z1, z2);
    Complex prod = multiply(z1, z2);

    printComplex(sum);

    printComplex(diff);

    printComplex(prod);

	return 0;
}
