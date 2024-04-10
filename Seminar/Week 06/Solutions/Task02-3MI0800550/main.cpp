#include "ToDo.hpp"

int main()
{
    ToDo a("Fitnes");
    std::cout << a.GetDescription() << std::endl;
    a.Do();
    std::cout << a.GetDescription() << std::endl;
    return 0;
}
