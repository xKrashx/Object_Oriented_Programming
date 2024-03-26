#ifndef __CARD_H
#define __CARD_H

#define MAX_BUFF_SIZE 100
#define MAX_DECK_SIZE 52
#define MAX_HAND_SIZE 13

enum Suit : char {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum Color : bool {
    RED,
    BLACK
};

enum Honor : char {
    J,
    Q,
    K,
    A
};

struct Card {
    Suit s;
    Color c;
    union 
    {
        int small;
        Honor honor;
    };
    bool isSmall;
};

void enterCard(Card& card);
void printCard(const Card& card);

struct {
    Card cards[MAX_DECK_SIZE] = {
        {HEARTS, RED, 2, true}, {HEARTS, RED, 3, true}, {HEARTS, RED, 4, true},
        {HEARTS, RED, 5, true}, {HEARTS, RED, 6, true}, {HEARTS, RED, 7, true},
        {HEARTS, RED, 8, true}, {HEARTS, RED, 9, true}, {HEARTS, RED, 10, true},
        {HEARTS, RED, J, false}, {HEARTS, RED, Q, false}, {HEARTS, RED, K, false},
        {HEARTS, RED, A, false},
        {DIAMONDS, RED, 2, true}, {DIAMONDS, RED, 3, true}, {DIAMONDS, RED, 4, true},
        {DIAMONDS, RED, 5, true}, {DIAMONDS, RED, 6, true}, {DIAMONDS, RED, 7, true},
        {DIAMONDS, RED, 8, true}, {DIAMONDS, RED, 9, true}, {DIAMONDS, RED, 10, true},
        {DIAMONDS, RED, J, false}, {DIAMONDS, RED, Q, false}, {DIAMONDS, RED, K, false},
        {DIAMONDS, RED, A, false},
        {CLUBS, BLACK, 2, true}, {CLUBS, BLACK, 3, true}, {CLUBS, BLACK, 4, true},
        {CLUBS, BLACK, 5, true}, {CLUBS, BLACK, 6, true}, {CLUBS, BLACK, 7, true},
        {CLUBS, BLACK, 8, true}, {CLUBS, BLACK, 9, true}, {CLUBS, BLACK, 10, true},
        {CLUBS, BLACK, J, false}, {CLUBS, BLACK, Q, false}, {CLUBS, BLACK, K, false},
        {CLUBS, BLACK, A, false},
        {SPADES, BLACK, 2, true}, {SPADES, BLACK, 3, true}, {SPADES, BLACK, 4, true},
        {SPADES, BLACK, 5, true}, {SPADES, BLACK, 6, true}, {SPADES, BLACK, 7, true},
        {SPADES, BLACK, 8, true}, {SPADES, BLACK, 9, true}, {SPADES, BLACK, 10, true},
        {SPADES, BLACK, J, false}, {SPADES, BLACK, Q, false}, {SPADES, BLACK, K, false},
        {SPADES, BLACK, A, false}
    };
    int size = MAX_DECK_SIZE;
} deck;

#endif