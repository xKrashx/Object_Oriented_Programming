#include <iostream>

// Този ред е лоша практика!
using namespace std;

// Това е грешна структура.
// Комплексно число се описва от реална и имагинерна част, което са 2 числа, а не 4!
struct ComplexNumbers{
    int a, b ,c ,d;
};

//function to enter the complex number
void enterComplexNumber(ComplexNumbers &number){
    cin >> number.a >> number.b;
    cin >> number.c >> number.d;
}

// Следващите 3 функции следва да имат функционалността да направят
// действие върху 2 комплексни числа и да върнат резултат, който е ново комплексно число.
//function to add the complex numbers
void addComplexNumbers(ComplexNumbers number){
    int real = number.a + number.c;
    int imaginary = number.b + number.d;

    if (real == 0) cout << imaginary << "i" << endl;
    else if (imaginary == 0) cout << real << endl;
    else cout << real << " + " << imaginary << "i" << endl;
}

//function to subtract the complex numbers
void subtractComplexNumbers(ComplexNumbers number){
    int real = number.a - number.c; 
    int imaginary = number.b - number.d;

    if (real == 0) cout << imaginary << "i" << endl;
    else if (imaginary == 0) cout << real << endl;
    else cout << real << " + " << imaginary << "i" << endl;
}

//function to multiply the complex numbers
void multiplyComplexNumbers(ComplexNumbers number){
    int real = (number.a * number.c) - (number.b * number.d);
    int imaginary = (number.a * number.d) + (number.b * number.c);

    if (real == 0) cout << imaginary << "i" << endl;
    else if (imaginary == 0) cout << real << endl;
    else cout << real << " + " << imaginary << "i" << endl;
}


int main(){
    ComplexNumbers number;

    enterComplexNumber(number);

    addComplexNumbers(number);
    subtractComplexNumbers(number);
    multiplyComplexNumbers(number);

    return 0;
}
