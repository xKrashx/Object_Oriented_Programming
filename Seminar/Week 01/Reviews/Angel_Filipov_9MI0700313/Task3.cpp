#include <iostream>
// Тази библиотека ви е строго забранено да я ползвате,
// освен ако не е казано изрично, че можете.
#include <vector>
// Тази библиотека няма да ви е разрешена освен, ако не е опоменато.
// За базови сортиращи алгоритми трябва да сте говорили по УП.
#include <algorithm> //sort
#include <iomanip> //setprecision
// Липсва cmath библиотеката!

//Задача 3
struct Complex {
   int real, im;

   //За operator+ съм използвал помощта на chatGPT и другите два ги направих като горния с променен знак.
    // Отново наблягам на това, че е добре написано, но материалът не е взиман и е хубаво да се въздържаме от такива неща.
   Complex operator+(const Complex& other) const {
       return { real + other.real, im + other.im };
   }

   Complex operator-(const Complex& other) const {
       return { real - other.real, im - other.im };
   }

   Complex operator*(const Complex& other) const {
       return {
           real * other.real - im * other.im,
           real * other.im + im * other.real
       };
   }

   void print() const {
       if (im == 0) {
           std::cout << real << std::endl;
       }

       else if (im > 0) {
           std::cout << real << "+" << im << "i" << std::endl;
       }
       else {
            // Този print е тотално грешен.
           std::cout << real << im << "i" << std::endl;
       }
   }
};

int main() {
   int a, b, c, d;
   std::cin >> a >> b >> c >> d;

   Complex z1 = { a, b };
   Complex z2 = { c, d };

   (z1 + z2).print();
   (z1 - z2).print();
   (z1 * z2).print();

   return 0;
}