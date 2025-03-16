#include <iostream>
#include <cmath>


struct QuadraticEquation {
    double a, b, c;

    // Същата забележка както 1ва задача. Придържай се към материала!
    void solve() {
   
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            std::cout << "The equation does not have real solutions!";
            return;
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            std::cout << "x1 = x2 = " << root;
            return;
        }
        else { 
            double sqrtDisc = std::sqrt(discriminant);
            double root1 = (-b - sqrtDisc) / (2 * a);
            double root2 = (-b + sqrtDisc) / (2 * a);
      
            if (root1 > root2) std::swap(root1, root2);
            std::cout << "x1 = " << root1 << ", x2 = " << root2;
            return;
        }
    }
};

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    QuadraticEquation eq{ a, b, c };
    eq.solve();

    return 0;
}
