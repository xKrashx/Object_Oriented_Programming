#include <iostream>
#include <cstring>

struct Procesor
{
    double hertz;
    unsigned cores, cache, threads;
};

class Laptop
{
public:
    Laptop();
    Laptop(const Laptop &other);
    Laptop(const char *brandName, int price, int screenSize, int ram, double batery_cap, Procesor cpu);
    Laptop &operator=(const Laptop &other);
    ~Laptop();

    void Print();
    void UpgradeCPU(const Procesor other);
    void UpgradeRAM(int new_ram);

private:
    char *brandName;
    int price;
    int screenSize;
    Procesor cpu;
    int ram;
    double batery_cap;

    void copy(const Laptop& other)
    {
        brandName = new (std::nothrow) char[strlen(other.brandName)+1];
        (this->brandName, other.brandName);
        price = other.price;
        screenSize = other.screenSize;
        ram = other.ram;
        batery_cap = other.batery_cap;
        cpu = other.cpu;
    }

    void free()
    {
        delete[] brandName;
    }
};