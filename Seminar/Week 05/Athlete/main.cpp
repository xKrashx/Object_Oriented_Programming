#include "Athlete.hpp"

int main(){

    Athlete first;
    Athlete second("Gosho", 2, 3, 1, false, "Bistriskite Tigri", Athlete::Sport::Volleyball);

    first.Print();
    second.Print();

    second.Train();
    second.Print();

    second.ChangeTeam("Maznite banici");
    second.Print();

    first.Train();
    first.Print();

    return 0;

}