#include <iostream>
#include <vector>

class Vehicle
{
private:
    char *make;
    char *model;
    int horsepower;

public:
    Vehicle() {}
    Vehicle(const Vehicle &objectToCopyFrom) {}
    Vehicle &operator=(const Vehicle &objectToCopyFrom) {}
    const char *getMake() const {}
    const char *getModel() const {}
    const int getHorsepower() const {}
    virtual void honk()
    {
        std::cout << "A vehicle honking\n";
    }
    ~Vehicle() {}
};

class Car : public Vehicle
{
private:
    int seats;

public:
    Car() : seats{1} {}
    void honk()
    {
        std::cout << "A car honking\n";
    }
    const int getSeats() const {}
};

class Motorcycle : public Vehicle
{
private:
    int capacityLuggage;

public:
    Motorcycle() : capacityLuggage{0} {}
    const int getCapacity() const {}
    void honk()
    {
        std::cout << "A motorcycle has no horn\n";
    }
};

int main()
{
    Vehicle v;
    Car c;
    Motorcycle m;
    v.honk();
    c.honk();
    m.honk();
    Vehicle *v1 = new Motorcycle(), *v2 = new Car();
    v1->honk();
    v2->honk();
    // std::vector<Vehicle *> vehicles{v1, v2, &v};
    // for (size_t i = 0; i < vehicles.size(); i++)
    // {
    //     vehicles[i]->honk();
    // }
}
