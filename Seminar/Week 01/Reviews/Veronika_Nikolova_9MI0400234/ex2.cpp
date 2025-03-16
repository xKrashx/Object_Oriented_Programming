#include <iostream> 
#include <cmath>

// Отново това е лоша практика
using namespace std;
 
struct QuadraticEquation { 
    double a, b, c;
 
    double discriminant() const{
        return pow(b, 2) - 4*a*c;
    }

    void findRoots() {
        double d = discriminant();
        if(d > 0) {
            double x1 = (-b - sqrt(d))/(2*a);
            double x2 = (-b + sqrt(d))/(2*a);
            std::cout << "x1 = " << x1 << " x2 = " << x2 << endl;
        } else if (d == 0){
            double x = -b/(2*a);
            std::cout << "x1 = x2 = " << x << endl;
        } else {
            std::cout << "The equation does not have real solutions!" << endl;
        }
    }
};
 
 
 
 
 
int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
 
    QuadraticEquation eq = {a, b, c};
    eq.findRoots();
    return 0;
 
}