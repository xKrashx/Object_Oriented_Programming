#include "MagicalBox.hpp"

int main(int argc, char const *argv[])
{
    MagicalBox M;

    M.insert(1);
    M.insert(16);
    M.insert(14);
    M.insert(12);

    std::cout << M.PickElement() << std::endl;
    
    return 0;
}
