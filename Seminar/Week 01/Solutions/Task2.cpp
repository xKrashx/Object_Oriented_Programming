#include <iostream>
#include <cstddef>
#include <limits>
#include <cmath>

size_t const UINT64_MAX_VALUE = UINT64_MAX;
double const NAN_CASTED = *(double *)&UINT64_MAX_VALUE;

struct Quadratic{
    double a, b, c, d, x1, x2;
};

void FindDiscriminant(Quadratic &equation){
    equation.d = equation.b * equation.b - 4 * equation.a * equation.c;
}

void Solve(Quadratic &equation){

    if(equation.d < 0) equation.x1 = equation.x2 = NAN_CASTED;
    else if(equation.d == 0) equation.x1 = equation.x2 = -equation.b / (2 * equation.a);
    else{

        equation.x1 = (-equation.b - sqrt(equation.d)) / (2 * equation.a);
        equation.x2 = (-equation.b + sqrt(equation.d)) / (2 * equation.a);

        if(equation.x1 > equation.x2) std::swap(equation.x1, equation.x2);

    }

}

int main(){

    Quadratic equation;

    std::cin >> equation.a >> equation.b >> equation.c;

    FindDiscriminant(equation);
    Solve(equation);

    if(equation.x1 == NAN_CASTED) std::cout << "The equation does not have real solutions!\n";
    else if(equation.x1 == equation.x2) std::cout << "x1 = x2 = " << equation.x1 << '\n';
    else std::cout << "x1 = " << equation.x1 << ", x2 = " << equation.x2 << '\n';

    return 0;

}