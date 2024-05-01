#include "Laptop.hpp"

int main()
{
    Procesor cpu = {1,2,2,2};
    Procesor cpu2 = {3.3,4,5,6};

    Laptop a("Helo", 12,1,2,3,cpu);
    a.UpgradeCPU(cpu2);
    a.UpgradeRAM(100);

    a.Print();
    return 0;
}
