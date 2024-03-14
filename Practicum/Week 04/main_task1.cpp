#include <iostream>
#include "Fraction.h"

int main() {
    Fraction frac1;
    frac1.setNumerator(3);
    frac1.setDenominator(4);

    Fraction frac2;
    frac2.setNumerator(1);
    frac2.setDenominator(2);

    std::cout << "Initial Fraction 1: "<< frac1.value() << " ";
    frac1.print();

    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Initial Fraction 2: "<< frac2.value()<< " ";
    frac2.print();
    

    frac1.add(frac2);
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Add Fraction 2 to Fraction 1: ";
    frac1.print();

    frac1.subtract(frac2);
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Subtract Fraction 2 from Fraction 1: ";
    frac1.print();

    frac1.divide(frac2);
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Divide Fraction 1 by Fraction 2: ";
    frac1.print();

    frac1.mult(frac2);
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Multiply Fraction 1 by Fraction 2: ";
    frac1.print();

    frac1.reverse();
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Reverse Fraction 1: ";
    frac1.print();

    bool result = frac1.compare(frac2);
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Compare Fraction 1 and Fraction 2: " << (result ? "Fraction 1 is smaller" : "Fraction 2 is smaller") << std::endl;

}