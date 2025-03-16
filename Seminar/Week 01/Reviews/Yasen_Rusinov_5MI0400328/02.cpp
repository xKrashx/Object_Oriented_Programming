#include <iostream>
#include <cmath>

struct  Equation {
  double a;
  double b;
  double c;
};

double findDiscriminant(const Equation &equation){
  return pow(equation.b, 2) - 4 * equation.a * equation.c;
}

void calculateRoots(Equation equation, double &x1, double &x2, const double &D){
  x1 = (-equation.b + sqrt(D)) / (2 * equation.a);
  x2 = (-equation.b - sqrt(D)) / (2 * equation.a);
}

void calculateRootsD0(Equation equation, double &x1, double &x2, const double &D){
  x1 = (-equation.b) / (2 * equation.a);
  x2 = (-equation.b) / (2 * equation.a);
}

int main(){
  Equation equation;
  std::cin >> equation.a;
  if (equation.a > 100 || equation.a < -100) {
    std::cout << "All coefficients must be between -100 and 100." << std::endl;
    return 0;
  }
  std::cin >> equation.b;
  if (equation.b > 100 || equation.b < -100) {
    std::cout << "All coefficients must be between -100 and 100." << std::endl;
    return 0;
  }
  std::cin >> equation.c;
  if (equation.c > 100 || equation.c < -100) {
    std::cout << "All coefficients must be between -100 and 100." << std::endl;
    return 0;
  }
  
  double x1, x2 = 0;
  double D = findDiscriminant(equation);

  if (D < 0) {
    std::cout << "This equation has no real roots." << std::endl;
    return 0;
  }
  else if (D == 0) {
    calculateRootsD0(equation, x1, x2, D);
    std::cout << "x1 = x2 = " << x1 << std::endl;
  }
  else if (D > 0) {
    calculateRoots(equation, x1, x2, D);
    std::cout << "x1 = " << x1 << ",  x2 = " << x2 << std::endl;
  }

  return 0;
}
