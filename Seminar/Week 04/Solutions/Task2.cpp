#include <iostream>

class Car{

    public:
        int getGas() const;
        int getHorsePower() const;
        int getDistanceTraveled() const;

        void setGas(const int &);
        void setHorsePower(const int &);
        void setDistanceTraveled(const int &);

        void upgrade();
        void fill();
        void drive(const int &);

    private:
        int gas, horsePower, distanceTraveled;

};

int Car::getGas() const{
    return gas;
}

int Car::getHorsePower() const{
    return horsePower;
}

int Car::getDistanceTraveled() const{
    return distanceTraveled;
}

void Car::setGas(const int &gas){
    this -> gas = gas;
}

void Car::setHorsePower(const int &horsePower){
    this -> horsePower = horsePower;
}

void Car::setDistanceTraveled(const int &distanceTraveled){
    this -> distanceTraveled = distanceTraveled;
}

void Car::upgrade(){

    if(horsePower == 150) return;
    horsePower = std::min(150, horsePower + 15);

}
void Car::fill(){
    gas = 100;
}

void Car::drive(const int &km){
    gas -= km * horsePower * 0.15;
}

int main(){

    Car myCar;

    myCar.fill();
    myCar.setHorsePower(90);
    myCar.setDistanceTraveled(0);

    myCar.drive(15);

    std::cout << myCar.getGas() << '\n';

    myCar.upgrade();
    myCar.fill();

    myCar.drive(15);

    std::cout << myCar.getGas() << '\n';

    return 0;

}