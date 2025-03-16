#include <iostream>
#include <cmath>

struct quadraticEquation
{
    double a;
    double b;
    double c;

    // За методи не е говорено, така че нека не бързаме с материала!
    void solve() const{
        if (a < -100 || a > 100 || b < -100 || b > 100 || c < -100 || c > 100)
        {
            std::cerr << "Error!\n";
        }

        double discriminant = b*b - 4*a*c;
        if (discriminant > 0)
        {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            if (root1 > root2)
            {
                std::swap(root1,root2);
            }
            std::cout << "x1 = " << root1 << ", x2 = " << root2 << '\n';
        }
        else if(discriminant == 0)
        {
            double root = -b / (2*a);
            std::cout << "x1 = x2 = " << root << '\n';
        }
        else{
            std::cout << "The equation does not have real solutions!" << std::endl;
        }
        
        
    }
};


int main()
{
    quadraticEquation equation;
    double a, b, c;
    std::cin >> a >> b >> c;

    equation.a = a;
    equation.b = b;
    equation.c = c;
    equation.solve();


    return 0;
}