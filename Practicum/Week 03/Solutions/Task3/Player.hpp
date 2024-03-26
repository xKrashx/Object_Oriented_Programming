#ifndef __PLAYER_H
#define __PLAYER_H

#include "Card.hpp"

struct Player {
    char name[MAX_BUFF_SIZE];
    Card hand[MAX_HAND_SIZE];
    int size = 0;
};

void dealSinglePlayer(Player& p);
void showHand(const Player& p);

#endif