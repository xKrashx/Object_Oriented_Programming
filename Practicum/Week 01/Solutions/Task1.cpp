#include <iostream>
#include <cstring>

const unsigned short REG_NUM_LEN = 9;
const unsigned short MAX_LEN = 10;

const char* carBrands[] = {"unknown", "BMW", "Audi", "Kia"};
const char* carColors[] = {"unknown", "black", "red", "blue"};

enum Brand
{
    UNKNOWN_BRAND,
    BMW,
    Audi,
    Kia,
    BRANDS_COUNT
};

enum Color
{
    UNKNOWN_COLOR,
    BLACK, 
    RED, 
    BLUE,
    COLORS_COUNT
};

struct Car
{
    char regNum[REG_NUM_LEN];
    Brand brand;
    Color color;
};

void readCar(Car& car)
{
    std::cout << "registration number: ";
    std::cin.getline(car.regNum, REG_NUM_LEN);

    char brand[MAX_LEN];
    std::cout << "brand: ";
    std::cin.getline(brand, MAX_LEN);

    bool found = false;
    for(int i = 1; i < BRANDS_COUNT && !found; i++)
    {
        if(strcmp(brand, carBrands[i]) == 0)
        {
            car.brand = (Brand) i;
            found = true;
        }
    }
    if(!found) car.brand = UNKNOWN_BRAND;

    char color[MAX_LEN];
    std::cout << "color: ";
    std::cin.getline(color, MAX_LEN);

    found = false;
    for(int i = 1; i < COLORS_COUNT && !found; i++)
    {
        if(strcmp(color, carColors[i]) == 0)
        {
            car.color = (Color) i;
            found = true;
        }
    }
    if(!found) car.color = UNKNOWN_COLOR;
}

void printCar(const Car& car)
{
    std::cout << "registration number: " << car.regNum           << std::endl
              << "brand: "               << carBrands[car.brand] << std::endl
              << "color: "               << carColors[car.color] << std::endl;
}

int main()
{
    Car car;
    readCar(car);
    std::cout << std::endl;
    printCar(car);
    return 0;
}