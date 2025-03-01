#pragma once

class Car
{
    private:
    double hp;
    double tank;
    double distance;

    public:
    Car();
    double getHp() const;
    double getTank() const;
    double getDistance() const;
    void Upgrade();
    void Fill();
    void Drive(double routeDistance);
    void print();
};