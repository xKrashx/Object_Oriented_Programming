#pragma once
#include "cards.h"

struct Player{
    int hand[13] = {0,};
    int cardsInHand = 0;
};

void PrintHand(const Player pl ,const Card deck[],const int cardsInDeck);
void PrintCard(const Card card);
void EnterCardInFile(const Player pl ,const Card deck[],const int cardsInDeck);