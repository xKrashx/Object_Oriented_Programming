// Същите забележки както на 1ва задача.
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct QuadraticEquation {
    double a, b, c;

    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void solve() {
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            cout << "The equation does not have real solutions!" << endl;
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "x1 = x2 = " << fixed << setprecision(6) << x << endl;
        }
        else {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            if (x1 > x2) swap(x1, x2);
            cout << "x1 = " << fixed << setprecision(6) << x1 << ", x2 = " << fixed << setprecision(6) << x2 << endl;
        }
    }
};

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    QuadraticEquation eq(a, b, c);
    eq.solve();

    return 0;
}
