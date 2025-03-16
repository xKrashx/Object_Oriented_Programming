#include <iostream>

// Това е грешна структура!
// Първо, би било логично да се казва ComplexNumber.
// Второ, едно комплексно число се описва от реална и имагинерна част,
// което е 2 числа, а не 4!
struct Imag {
  int a;
  int b;
  int c;
  int d;
};

// Константна референция!!!
// Липсват скоби също така!
// Тези функции би следвало да взимат две комплексни числа и да връщат
// ново комплексно число, което е резултатът от операцията!!
void addition(Imag &number)
  std::cout << number.a + number.c << "+" << number.b + number.d << "i" << std::endl;
}
void subtraction(Imag &number)
  std::cout << number.a - number.c << "+" << number.b - number.d << "i" << std::endl;
}
void multiplication(Imag &number)
  std::cout << number.a * number.c - number.b * number.d << "+" << number.a * number.d + number.b * number.c << "i" << std::endl;
}

int main(){
  Imag number;
  std::cin >> number.a;
  if (!(-1000 <= number.a <= 1000)) {
    std::cout << "All coefficient must be between -1000 and 1000." << std::endl;
    return 1;
  }
  std::cin >> number.b;
  if (!(-1000 <= number.b <= 1000)) {
    std::cout << "All coefficient must be between -1000 and 1000." << std::endl;
    return 1;
  }
  std::cin >> number.c;
  if (!(-1000 <= number.c <= 1000)) {
    std::cout << "All coefficient must be between -1000 and 1000." << std::endl;
    return 1;
  }
  std::cin >> number.d;
  if (!(-1000 <= number.d <= 1000)) {
    std::cout << "All coefficient must be between -1000 and 1000." << std::endl;
    return 1;
  }

  addition(number);
  subtraction(number);
  multiplication(number);

  return 0;
}
