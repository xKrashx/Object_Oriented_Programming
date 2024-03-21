#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "player.h"
#include "cards.h"

const char * suit[] = {
    "CLUBS",
    "SPADES",
    "DIAMONDS",
    "HEARTS"
};
const char * colors[] = {
    "RED",
    "BLACK"
};

int rangeRandomAlg2 (int min, int max){
 
	
	int random = min + (rand() % (max - min + 1));
	return random;
}
int main()
{
    Card deck[52];
    char delims [] = {' ','\n'};
	srand((unsigned) time(NULL));
    std::ifstream file ("cards.txt");
    const size_t numberOfCardsInDeck = 52;
    size_t counter = 0;
    while (!file.eof())
    {    
        if(file.peek()=='\n'){file.get();}
        else{
            Card newCard;
            char input [10];
            file.getline(input,10,' ');
            for(size_t i=0;i< sizeof(suit)/sizeof(char*);i++)if(!strcmp(input,suit[i]))newCard.suit = (Suit)i;
            file.getline(input,10,' ');
            for(size_t i=0;i< sizeof(colors)/sizeof(char*);i++)if(!strcmp(input,colors[i]))newCard.color = (Color)i;
            file.getline(input,10,'\n');
            newCard.Honor[0] = input[0];
            if(newCard.Honor[0]=='1')newCard.Honor[1] = '0';
            deck[counter] = newCard;
            counter ++;
        }
    }

    Player player1;
    Player player2;
    Player player3;
    Player player4;
    int currentCard = 0;
    while(player1.cardsInHand+player2.cardsInHand+player3.cardsInHand+player4.cardsInHand != numberOfCardsInDeck){
        int random = rangeRandomAlg2(1,4);
        switch (random)
        {
        case 1:
        if(player1.cardsInHand == 13)break;
            player1.hand[player1.cardsInHand] = currentCard;
            player1.cardsInHand +=1;currentCard +=1;
            break;
         case 2:
         if(player2.cardsInHand == 13)break;
            player2.hand[player2.cardsInHand] = currentCard;
            player2.cardsInHand +=1;currentCard +=1;
            break;
         case 3:
         if(player3.cardsInHand == 13)break;
            player3.hand[player3.cardsInHand] = currentCard;
            player3.cardsInHand +=1;currentCard +=1;
            break;
         case 4:
         if(player4.cardsInHand == 13)break;
            player4.hand[player4.cardsInHand] = currentCard;
            player4.cardsInHand += 1;currentCard +=1;
            break;
        default:
            break;
        }
    }

    EnterCardInFile(player1,deck,numberOfCardsInDeck);
    EnterCardInFile(player2,deck,numberOfCardsInDeck);
    EnterCardInFile(player3,deck,numberOfCardsInDeck);
    EnterCardInFile(player4,deck,numberOfCardsInDeck);
    return 0;
}