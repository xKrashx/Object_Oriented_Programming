#include <iostream>
#include <cmath>

// По условие пишеше да се използват реални числа(double).
// Такова уточнение би ти коствало точки на контролно/изпит.
struct QuadraticEquation
{
    int a;
    int b;
    int c;
};

void inputCoefficients(QuadraticEquation &equation);
void calculate(QuadraticEquation &equation);

int main()
{
    QuadraticEquation equation;
    std::cout << "Enter the coefficients of the quadratic equation:" << std::endl;
    inputCoefficients(equation);

    calculate(equation);

    return 0;
}

void inputCoefficients(QuadraticEquation &equation)
{
    bool valid;

    do
    {
        valid = true;
        std::cin >> equation.a >> equation.b >> equation.c;
        if (!((equation.a >= -100 && equation.a <= 100) &&
              (equation.b >= -100 && equation.b <= 100) &&
              (equation.c >= -100 && equation.c <= 100)))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (valid == false);
}

void calculate(QuadraticEquation &equation)
{
    int discriminant = equation.b * equation.b - 4 * equation.a * equation.c;

    if (discriminant < 0)
    {
        std::cout << "The equation does not have real solitions!" << std::endl;
    }
    else if (discriminant == 0)
    {
        double solution = (-equation.b) / (2 * equation.a);
        std::cout << "x1 = x2 = " << solution << std::endl;
    }
    else
    {
        double solution1 = (-equation.b + sqrt(discriminant)) / (2 * equation.a);
        double solution2 = (-equation.b - sqrt(discriminant)) / (2 * equation.a);

        if (solution1 < solution2)
        {
            std::cout << "x1 = " << solution1 << ", x2 = " << solution2 << std::endl;
        }
        else
        {
            std::cout << "x1 = " << solution2 << ", x2 = " << solution1 << std::endl;
        }
    }
}