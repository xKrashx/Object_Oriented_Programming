#include <iostream>

struct ComplexNumber
{
    int a;
    int b;
};

void inputCoefficients(ComplexNumber &complex);
ComplexNumber additionComplex(ComplexNumber complex1, ComplexNumber complex2);
ComplexNumber subtractionComplex(ComplexNumber complex1, ComplexNumber complex2);
ComplexNumber multiplicationComplex(ComplexNumber complex1, ComplexNumber complex2);
void printComplex(ComplexNumber additionComplex, ComplexNumber subtractionComplex, ComplexNumber multiplicationComplex);

int main()
{
    ComplexNumber complex1;
    ComplexNumber complex2;

    std::cout << "Enter the complex numbers:" << std::endl;
    inputCoefficients(complex1);
    inputCoefficients(complex2);

    ComplexNumber addition = additionComplex(complex1, complex2);
    ComplexNumber subtraction = subtractionComplex(complex1, complex2);
    ComplexNumber multiplication = multiplicationComplex(complex1, complex2);

    printComplex(addition, subtraction, multiplication);

    return 0;
}

void inputCoefficients(ComplexNumber &complex)
{
    bool valid;

    do
    {
        valid = true;
        std::cin >> complex.a >> complex.b;

        if (!((complex.a >= -1000 && complex.a <= 1000) &&
              (complex.b >= -1000 && complex.b <= 1000)))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (valid == false);
}

ComplexNumber additionComplex(ComplexNumber complex1, ComplexNumber complex2)
{
    ComplexNumber result;

    result.a = complex1.a + complex2.a;
    result.b = complex1.b + complex2.b;

    return result;
}

ComplexNumber subtractionComplex(ComplexNumber complex1, ComplexNumber complex2)
{
    ComplexNumber result;

    result.a = complex1.a - complex2.a;
    result.b = complex1.b - complex2.b;

    return result;
}

ComplexNumber multiplicationComplex(ComplexNumber complex1, ComplexNumber complex2)
{
    ComplexNumber result;

    result.a = (complex1.a * complex2.a) - (complex1.b * complex2.b);
    result.b = (complex1.a * complex2.b) + (complex1.b * complex2.a);

    return result;
}

// Това е лоша практика да направиш print функция, която изисква точно 3 комплексни числа.
// Какво става ако искам да покажа по-малко, или повече?
void printComplex(ComplexNumber addition, ComplexNumber subtraction, ComplexNumber multiplication)
{
    if (addition.a != 0)
    {
        std::cout << addition.a << " ";
    }
    if (addition.b < 0)
    {
        std::cout << addition.b << "i" << std::endl;
    }
    else if (addition.b == 0)
    {
        std::cout << std::endl;
    }
    else
    {
        std::cout << "+ " << addition.b << "i" << std::endl;
    }

    if (subtraction.a != 0)
    {
        std::cout << subtraction.a << " ";
    }
    if (subtraction.b < 0)
    {
        std::cout << subtraction.b << "i" << std::endl;
    }
    else if (subtraction.b == 0)
    {
        std::cout << std::endl;
    }
    else
    {
        std::cout << "+ " << subtraction.b << "i" << std::endl;
    }

    if (multiplication.a != 0)
    {
        std::cout << multiplication.a << " ";
    }
    if (multiplication.b < 0)
    {
        std::cout << multiplication.b << "i" << std::endl;
    }
    else if (multiplication.b == 0)
    {
        std::cout << std::endl;
    }
    else
    {
        std::cout << "+ " << multiplication.b << "i" << std::endl;
    }
}