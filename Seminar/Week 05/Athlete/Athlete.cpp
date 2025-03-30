#include "Athlete.hpp"
#include <iostream>
#include <cstring>
#include <new>

Athlete::Athlete(){

    // Стойности по подразбиране, ако не подадем аргументи
    name = team = nullptr;
    stamina = speed = power = 1;
    trauma = false;
    sport = Sport::Football;

}

// Параметризиран конструктор с инизиализиращ списък.
Athlete::Athlete(char const *name, int stamina, int speed, int power, bool trauma, char const *team, Sport sport):
name(new(std::nothrow) char[strlen(name) + 1]), stamina(stamina), speed(speed), power(power), trauma(trauma), team(new(std::nothrow) char[strlen(team) + 1]), sport(sport){

    if(this -> name) strcpy(this -> name, name);
    if(this -> team) strcpy(this -> team, team);

}

Athlete::~Athlete (){

    delete[] name;
    delete[] team;

}

char const *Athlete::GetName() const{
    return this -> name;
}

int Athlete::GetStamina() const{
    return this -> stamina;
}

int Athlete::GetSpeed() const{
    return this -> speed;
}

int Athlete::GetPower() const{
    return this -> power;
}

bool Athlete::GetTrauma() const{
    return this -> trauma;
}

char const *Athlete::GetTeam() const{
    return this -> team;
}

Athlete::Sport Athlete::GetSport() const{
    return this -> sport;
}

void Athlete::ChangeTeam(char const *team){

    // Ако вече имаме заделена памет за бившия отбор искаме да я освободим, преди да го сменим.
    delete[] this -> team;
    // Заделяме новата памет и присвояваме стойността.
    this -> team = new(std::nothrow) char[strlen(team) + 1];
    strcpy(this -> team, team);

}

void Athlete::Train(){

    // Ако има травма не може да тренира.
    if(trauma) return;

    power = std::min(power + 1, 5);
    stamina = std::min(stamina + 1, 5);
    speed = std::min(speed + 1, 5);

}

void Athlete::Print() const{

    // Проверяваме за името и за отбора дали има заделено масив за името, защото не можем да печатаме nullptr.
    std::cout << (name ? name : "\0") << ' '
        << '0' + power << ' '
        << '0' + speed << ' '
        << '0' + stamina << ' '
        << trauma << ' '
        << (team ? team : "\0") << ' ';

    switch(sport){

        case Sport::Football:
            std::cout << "Football\n";
            break;

        case Sport::Volleyball:
            std::cout << "Volleyball\n";
            break;

        case Sport::Basketball:
            std::cout << "Basketball\n";
            break;

        case Sport::Tennis:
            std::cout << "Tennis\n";
            break;
        
        default:
            break;

    }

}