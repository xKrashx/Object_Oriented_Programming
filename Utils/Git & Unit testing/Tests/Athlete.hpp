#pragma once

#include "Sports.hpp"
#define TEST_IN_MAIN true

class Athlete{

    public:
        Athlete();
        Athlete(char const * const &, int const &, int const &, int const &, bool const &, char const * const &, Sport const &);
        ~Athlete();

        char const *getName() const;
        int getStamina() const;
        int getSpeed() const;
        int getPower() const;
        bool getTrauma() const;
        char const *getTeam() const;
        Sport getSport() const;

        void changeTeam(char const * const &);
        void train();
        void print() const;

    private:
        char *name;
        int stamina, speed, power;
        bool trauma;
        char *team;
        Sport sport;

};