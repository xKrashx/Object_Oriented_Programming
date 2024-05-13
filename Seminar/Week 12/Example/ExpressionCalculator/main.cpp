#include "ExpressionCalculator.hpp"
#include <iostream>

int main(){

	ExpressionCalculator ta("(Pv(!P))");
	ExpressionCalculator c("(P^(!P))");
	ExpressionCalculator random("(((PvQ)^(TvR))v(!P))");

	std::cout << std::boolalpha << ta.IsTautology() << std::endl;
	std::cout << std::boolalpha << ta.IsContradiction() << std::endl;

	std::cout << std::boolalpha << c.IsTautology() << std::endl;
	std::cout << std::boolalpha << c.IsContradiction() << std::endl;

	std::cout << std::boolalpha << random.IsTautology() << std::endl;
	std::cout << std::boolalpha << random.IsContradiction() << std::endl;

    return 0;

}