#include <iostream>

enum Color { red, green, blue };                    // plain enum 
enum Card { red_card, green_card, yellow_card };    // another plain enum 
enum class Animal { dog, deer, cat, bird, human };  // enum class
enum class Mammal { kangaroo, deer, human };        // another enum class

int main(){

    // examples of bad use of plain enums:
    Color color = Color::red;
    Card card = Card::green_card;

    int num = color;    // no problem

    if (color == Card::red_card) // no problem (bad)
        std::cout << "bad\n";

    if (card == Color::green)   // no problem (bad)
        std::cout << "bad\n";

    // examples of good use of enum classes (safe)
    Animal a = Animal::deer;
    Mammal m = Mammal::deer;

    int num2 = a;   // error
    if (m == a)         // error (good)
        std::cout << "bad\n";

    if (a == Mammal::deer) // error (good)
        std::cout << "bad\n";

}