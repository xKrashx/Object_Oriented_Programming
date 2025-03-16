#include <iostream>
#include <cmath>

// Отново, това е лоша практика!
using namespace std;

struct QuadraticEquation {

    double a, b, c;

    // Методи все още не са учени, така че се въздържаме от употребата им.
    void computate() {

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {

            cout << "The equation does not have real solutions!" << endl;
        }
        else if (discriminant == 0) {

            double root = -b / (2 * a);
            cout << "x1 = x2 = " << root << endl;
        }
        else {

            double root1 = (-b - sqrt(discriminant)) / (2 * a);
            double root2 = (-b + sqrt(discriminant)) / (2 * a);
            if (root1 > root2) swap(root1, root2);
            cout << "x1 = " << root1 << ", x2 = " << root2 << endl;
        }
    }
};

int main() {

    double a, b, c;
    cin >> a >> b >> c;
    QuadraticEquation equation = { a, b, c };
    equation.computate();
    return 0;
}