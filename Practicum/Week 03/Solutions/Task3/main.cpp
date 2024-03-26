#include <iostream>
#include "Player.hpp"

int main() {
    Player p1, p2, p3, p4;
    Player players[] = {p1, p2, p3, p4};
    const short numPlayers = sizeof(players) / sizeof(players[0]);
    for (int i = 0; i < numPlayers; i++)
    {
        std::cout << "Enter player " << i + 1 << " name: ";
        std::cin.getline(players[i].name, MAX_BUFF_SIZE);
    }
    for (int i = 0; i < numPlayers; i++) 
    {
        dealSinglePlayer(players[i]);
    }
    for (int i = 0; i < numPlayers; i++) 
    {
        showHand(players[i]);
    }
    return 0;
}