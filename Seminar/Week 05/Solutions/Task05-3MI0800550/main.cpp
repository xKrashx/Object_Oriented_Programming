#include "Range.hpp"

int main()
{
    Range A(10, 13);
    Range B(-1, 22);

    Range C = A.Union(B);

    std::cout << A.NumOfPalindromes() << std::endl;

    return 0;
}