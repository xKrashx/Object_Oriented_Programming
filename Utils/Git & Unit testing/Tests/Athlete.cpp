#include <iostream>
#include <cstring>

#include "Athlete.hpp"

using std::min;
using std::cout;
using std::nothrow;

Athlete::Athlete(){

    name = team = nullptr;
    stamina = speed = power = 1;
    trauma = false;
    sport = Sport::Football;

}

Athlete::Athlete(char const * const &name, int const &stamina, int const &speed, int const &power, bool const &trauma, char const * const &team, Sport const &sport):
name(new(nothrow) char[strlen(name) + 1]), stamina(stamina), speed(speed), power(power), trauma(trauma), team(new(nothrow) char[strlen(team) + 1]), sport(sport){

    if(this -> name) strcpy(this -> name, name);
    if(this -> team) strcpy(this -> team, team);

}

Athlete::~Athlete (){

    delete[] name;
    delete[] team;

}

char const *Athlete::getName() const{
    return this -> name;
}

int Athlete::getStamina() const{
    return this -> stamina;
}

int Athlete::getSpeed() const{
    return this -> speed;
}

int Athlete::getPower() const{
    return this -> power;
}

bool Athlete::getTrauma() const{
    return this -> trauma;
}

char const *Athlete::getTeam() const{
    return this -> team;
}

Sport Athlete::getSport() const{
    return this -> sport;
}
void Athlete::changeTeam(char const * const &team){

    delete[] this -> team;
    this -> team = new(nothrow) char[strlen(team) + 1];
    strcpy(this -> team, team);

}

void Athlete::train() {

    if(trauma) return;

    power = min(power + 1, 5);
    stamina = min(stamina + 1, 5);
    speed = min(speed + 1, 5);

}

void Athlete::print() const
{
    cout << (name ? name : "\0") << ' '
        << power << ' '
        << speed << ' '
        << stamina << ' '
        << trauma << ' '
        << (team ? team : "\0") << ' ';
    switch (sport){

        case Sport::Football:
            cout << "Football\n";
            break;

        case Sport::Voleyball:
            cout << "Voleyball\n";
            break;

        case Sport::Basketball:
            cout << "Basketball\n";
            break;

        case Sport::Tennis:
            cout << "Tennis\n";
            break;
        
        default:
            break;

    }

}