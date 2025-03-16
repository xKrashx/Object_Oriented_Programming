#include "car.hpp"
#include <iostream>
    Car::Car(){
        this->hp = 90;
        this->distance = 0;
        this->tank = 0;
    }
    double Car::getHp() const{return hp;}
    double Car::getTank() const{return tank;}
    double Car::getDistance() const{return distance;}
    void Car::Upgrade(){
        if(this->hp+15 >150)this->hp = 150;
        else this->hp+=15;
    }
    void Car::Fill(){
        this->tank = 100;
    }
    void Car::Drive(double routeDistance){
        if (this->tank <routeDistance*(this->hp/15))
        {
            std::cout<<"Not Enought Gas";
        }
        else{
            this->tank -= routeDistance*(this->hp/15);
            this->distance+=routeDistance;
        }
    }
    void Car::print(){
        std::cout<<"hp ->"<<this->hp<<" tank ->"<<this->tank<<" distance->"<<this->distance<<std::endl;
    }
    
