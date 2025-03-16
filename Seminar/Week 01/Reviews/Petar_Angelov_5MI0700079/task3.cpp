#include <iostream>
// Този ред е много лоша практика!
using namespace std;
 
struct Complex {
    int real;
    int imag;
};
 
Complex add(const Complex &z1, const Complex &z2) {
    return {z1.real + z2.real, z1.imag + z2.imag};
}
 
Complex subtract(const Complex &z1, const Complex &z2) {
    return {z1.real - z2.real, z1.imag - z2.imag};
}
 
Complex multiply(const Complex &z1, const Complex &z2) {
    return {z1.real * z2.real - z1.imag * z2.imag, z1.real * z2.imag + z1.imag * z2.real};
}
 
void printComplex(const Complex &z) {
    if(z.real == 0 && z.imag == 0) {
        cout << "0";
    } else if(z.imag == 0) {
        cout << z.real;
    } else if(z.real == 0) {
        if(z.imag == 1)
            cout << "i";
        else if(z.imag == -1)
            cout << "-i";
        else
            cout << z.imag << "i";
    } else {
        cout << z.real;
        if(z.imag > 0)
            cout << "+" << (z.imag == 1 ? "i" : to_string(z.imag) + "i");
        else
            cout << (z.imag == -1 ? "-i" : to_string(z.imag) + "i");
    }
}
 
int main(){
    Complex z1, z2;
    cin >> z1.real >> z1.imag >> z2.real >> z2.imag;
    Complex sum = add(z1, z2);
    Complex diff = subtract(z1, z2);
    Complex prod = multiply(z1, z2);
    printComplex(sum);
    cout << "\n";
    printComplex(diff);
    cout << "\n";
    printComplex(prod);
    return 0;
}
