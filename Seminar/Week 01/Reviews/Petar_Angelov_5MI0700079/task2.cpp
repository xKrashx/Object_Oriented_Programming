// Същите забележки като първа задача!
#include <iostream>
#include <cmath>
using namespace std;
 
struct Quadratic {
    double a, b, c;
};
 
int main(){
    Quadratic eq;
    cin >> eq.a >> eq.b >> eq.c;
    // Можеш да разделиш кода си по функции, за да е малко по-разбираемо какво правиш,
    // вместо всичко да е в main функцията.
    double discriminant = eq.b * eq.b - 4 * eq.a * eq.c;
    if(discriminant < 0) {
        cout << "The equation does not have real solutions!";
    } else if(discriminant == 0) {
        double root = -eq.b / (2 * eq.a);
        cout << "x1 = x2 = " << root;
    } else {
        double sqrtD = sqrt(discriminant);
        double x1 = (-eq.b - sqrtD) / (2 * eq.a);
        double x2 = (-eq.b + sqrtD) / (2 * eq.a);
        if(x1 > x2) std::swap(x1, x2);
        cout << "x1 = " << x1 << ", x2 = " << x2;
    }
    return 0;
}
