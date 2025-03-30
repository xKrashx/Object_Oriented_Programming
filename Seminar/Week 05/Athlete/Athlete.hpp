#ifndef __ATHLETE_H
#define __ATHLETE

class Athlete{

public:
    // enum е най-добре да бъде scoped(class), за да може да използваме само самите стойности(да не можем да използваме числа).
    // Дефиниран е вътре в класа, тъй като в нашия случай ще се отнася само за атлетите.
    // Ако им употреба някъде другаде трябва да бъде извън него.
    enum class Sport : char{

        Football,
        Basketball,
        Volleyball,
        Tennis

    };

    // Жизнен цикъл
    Athlete();
    Athlete(char const *name, int stamina, int speed, int power, bool trauma, char const *team, Sport sport);
    ~Athlete();

    // Get-ери
    char const *GetName() const;
    int GetStamina() const;
    int GetSpeed() const;
    int GetPower() const;
    bool GetTrauma() const;
    char const *GetTeam() const;
    Sport GetSport() const;

    // Мутатори(променят полетата на класа)
    void ChangeTeam(char const *);
    void Train();

    // Функция за принтиране
    void Print() const;

private:
    // Динамични низове за имената на атлета и отбора.
    char *name, *team;
    // Тези полета са оставени като char, с цел спестяване на памет. Вместо 3х4b, имаме 3х1b.
    char stamina, speed, power;
    Sport sport;
    bool trauma;

};

#endif