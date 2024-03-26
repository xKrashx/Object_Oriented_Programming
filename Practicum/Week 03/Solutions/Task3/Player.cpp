#include "Player.hpp"
#include <iostream>

void dealSinglePlayer(Player& p) {
    for (int i = 0; i < MAX_HAND_SIZE; i++) {
        p.hand[i] = deck.cards[deck.size - 1];
        deck.size--;
        p.size++;
    }
}

void showHand(const Player& p) {
    std::cout << p.name << " has the following cards: " << std::endl;
    for (int i = 0; i < p.size; i++) {
        printCard(p.hand[i]);
    }
    std::cout << "-------------------" << std::endl;
}