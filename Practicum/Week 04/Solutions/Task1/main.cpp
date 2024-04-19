#include <iostream>

#include "Fraction.hpp"

int main() 
{
    Fraction frac1;
    frac1.Init(3, 4);

    Fraction frac2;
    frac2.SetNumerator(1);
    frac2.SetDenominator(2);

    std::cout << "Initial Fraction 1: "<< frac1.Value() << " ";
    frac1.Print();
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Initial Fraction 2: "<< frac2.Value()<< " ";
    frac2.Print();
    

    frac1.Add(frac2);
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Add Fraction 2 to Fraction 1: ";
    frac1.Print(); // 5/4

    frac1.Subtract(frac2);
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Subtract Fraction 2 from Fraction 1: ";
    frac1.Print(); // 3/4

    frac1.Divide(frac2);
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Divide Fraction 1 by Fraction 2: ";
    frac1.Print(); // 3/2

    frac1.Mult(frac2);
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Multiply Fraction 1 by Fraction 2: ";
    frac1.Print(); // 3/4

    frac1.Reverse(); 
    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Reverse Fraction 1: ";
    frac1.Print(); // 4/3

    std::cout << std::endl << "---------------------------------" << std::endl;
    std::cout << "Compare Fraction 1 and Fraction 2: ";
    if(frac1.IsEqual(frac2))
    {
        frac1.Print();
        std::cout << " is equal to " << std::endl;
        frac2.Print();
        std::cout << std::endl;
    }
    else if(frac1.IsLessThan(frac2))
    {
        frac1.Print();
        std::cout << " is less than ";
        frac2.Print();
        std::cout << std::endl;
    }
    else
    {
        frac1.Print();
        std::cout << " is greater than ";
        frac2.Print();
        std::cout << std::endl;
    }
    
    return 0;
}
