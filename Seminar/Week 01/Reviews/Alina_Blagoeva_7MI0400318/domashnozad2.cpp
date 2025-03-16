#include <iostream>

// Бих предпочел коефициентите да са double(реални числа), както е по условие.
struct QuadraticEquation {
    int a;
    int b;
    int c;
};

void readEquation(QuadraticEquation &equation) {
    int a, b, c;

    //TO DO: validation of the input
    std::cout << "enter a b c for quadratic equation\n-100 <= a, b, c <= 100\na = " << std::endl;
    std::cin >> a;
    std::cout << "b = " << std::endl;
    std::cin >> b;
    std::cout << "c = " << std::endl;
    std::cin >> c;

    equation.a = a;
    equation.b = b;
    equation.c= c;
}

void findSolutions(const QuadraticEquation &equation) {
    int a = equation.a, b = equation.b, c = equation.c;

    // Нямаш cmath!
    double d = sqrt(b*b - 4*a*c);

    if (d > 0) {
        double x1 = (-b + d) / (2 * a);
        double x2 = (-b - d) / (2 * a);

        //to do: format the output better
        std::cout << "x1 = " << x1 << " x2 = " << x2 << std::endl;
    }
    else if (d == 0) {
        double x1 = (- b)/(2*a);
        std::cout << "x1 = x2 = " << x1 << std::endl;
    }
    else {
        std::cout << "The equation does not have real solutions!" << std::endl;
    }

}


int main()
{
    QuadraticEquation test;

    readEquation(test);
    findSolutions(test);
}

