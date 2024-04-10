#include "Laptop.hpp"

Laptop::Laptop()
{
    brandName = nullptr;
    price = 0;
    screenSize = 0;
    ram = 0;
    batery_cap = 0;
};

Laptop::Laptop(const Laptop &other)
{
    copy(other);
};

Laptop::Laptop(const char *brandName, int price, int screenSize, int ram, double batery_cap, Procesor cpu)
{
    this->brandName = new (std::nothrow) char[strlen(brandName) + 1];
    strcpy(this->brandName, brandName);
    this->price = price;
    this->screenSize = screenSize;
    this->ram = ram;
    this->batery_cap = batery_cap;
    this->cpu = cpu;
};

Laptop &Laptop::operator=(const Laptop &other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
};

Laptop::~Laptop()
{
    free();
}

void Laptop::Print()
{
    std::cout << "Model: " << this->brandName << std::endl;
    std::cout << "Price: " << this->price << std::endl;
    std::cout << "Screen Size: " << this->screenSize << std::endl;
    std::cout << "CPU: " << this->cpu.hertz << "Hz, " << this->cpu.cores << " cores, " << this->cpu.threads << " threads, " << this->cpu.cache << "MB cache" << std::endl;
    std::cout << "RAM: " << this->ram << "GB" << std::endl;
    std::cout << "Battery: " << this->batery_cap << "mAh" << std::endl;
}

void Laptop::UpgradeCPU(const Procesor other)
{
    this->cpu.hertz = other.hertz; 
    this->cpu.cores = other.cores; 
    this->cpu.threads = other.threads; 
    this->cpu.cache = other.cache; 
}

void Laptop::UpgradeRAM(int new_ram)
{
    this->ram = new_ram;
};

