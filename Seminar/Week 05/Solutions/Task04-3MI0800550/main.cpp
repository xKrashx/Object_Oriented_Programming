#include "Time.hpp"

int main()
{
    Time time(21, 0, 0);
    Time Timeb(20, 0, 0);
    std::cout << Timeb - time << std::endl;
    // std::cout << time.IsTimeForDinner() << std::endl;
    return 0;
}