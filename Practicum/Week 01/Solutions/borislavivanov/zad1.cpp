#include <iostream>
#include <cstring>
const size_t inputLenght=41;
const size_t PlateNumLenght = 9;


enum Brands{
    mitsubishi,
    mazda,
    opel
};
const char *brands[3] = {
    "mitsubishi",
    "mazda",
    "opel"
};
const char *colors[3] = {
    "red",
    "green",
    "blue"
};

enum Colors{
    red,
    green,
    blue
};

struct car{
    Brands brand;
    char PlateNum [PlateNumLenght];
    Colors color;
};

int main(){
    car newCar;
    char input[inputLenght];
    std::cin.getline(input,inputLenght);
    for(size_t i =0 ;i< sizeof(brands)/sizeof(char*);i++)if(!strcmp(input,brands[i]))newCar.brand = (Brands)i;
    std::cin.getline(newCar.PlateNum,PlateNumLenght);
    std::cin.getline(input,inputLenght);
    for(size_t i =0 ;i< sizeof(colors)/sizeof(char*);i++)if(!strcmp(input,colors[i]))newCar.color = (Colors)i;

    std::cout<<"Brand "<<brands[newCar.brand]<<std::endl<<"plateNum "<<newCar.PlateNum<<std::endl
    <<"color "<<colors[newCar.color];
    return 0;
}