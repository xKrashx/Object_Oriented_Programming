#pragma once
enum Suit{
    CLUBS,
    SPADES,
    DIAMONDS,
    HEARTS
};

enum Color{
    RED,
    BLACK
};

struct Card{
    Suit suit;
    Color color;
    char Honor[2];
    Card(){
    Honor[0] = ' ';
    Honor[1] = ' ';
    }
};


