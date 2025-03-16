#include "car.hpp"
#include <iostream>

int main(){
    double distanceToTravel = 0;
    std::cin>>distanceToTravel;
    Car newCar;
    newCar.print();
    newCar.Fill();
    newCar.print();
    newCar.Upgrade();
    newCar.print();
    newCar.Drive(distanceToTravel);
    newCar.print();
    return 0;

}