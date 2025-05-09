#include "player.h"
#include "cards.h"
#include <iostream>
#include <fstream>

const char * suits[] = {
    "CLUBS",
    "SPADES",
    "DIAMONDS",
    "HEARTS"
};

const char * color[] = {
    "RED",
    "BLACK"
};

void PrintHand(const Player pl ,const Card deck[],const int cardsInDeck){
    
    for(size_t i =0;i< pl.cardsInHand;i++){
        std::cout<<suits[deck[pl.hand[i]].suit]<<' ';
        std::cout<<color[deck[pl.hand[i]].color]<<' ';
        std::cout<<deck[pl.hand[i]].Honor[0]<<deck[pl.hand[i]].Honor[1]<<' '<<std::endl;
    }
}
void PrintCard(const Card card){
    std::cout<<suits[card.suit]<<' '<<color[card.color]<<' '<<card.Honor[0]<<card.Honor[1]<<'\n';
}

void EnterCardInFile(const Player pl ,const Card deck[],const int cardsInDeck){
    
    std::ofstream file("result.txt", std::ios::app);
     for(size_t i =0;i< pl.cardsInHand;i++){
        file<<color[deck[pl.hand[i]].color]<<' ';
        file<<suits[deck[pl.hand[i]].suit]<<' ';
        file<<deck[pl.hand[i]].Honor[0]<<deck[pl.hand[i]].Honor[1]<<' '<<std::endl;
    }
    file<<'\n';
   
}