#include <iostream>
#include <cstring>
#include <cstdlib>

int rangeRandomAlg2 (int min, int max){
 
	// Get a random number
	int random = min + (rand() % (max - min + 1));

	// Print the random number
	return random;
}

struct Player{
    int hand[13] = {0,};
    int cardsInHand = 0;
};

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

struct Card{
    Suit suit;
    Color color;
    char Honor[2];
};

void PrintHand(Player pl ,Card deck[],int cardsInDeck){
    
    for(size_t i =0;i< pl.cardsInHand;i++){
        std::cout<<suits[deck[pl.hand[i]].suit]<<' ';
        std::cout<<color[deck[pl.hand[i]].color]<<' ';
        std::cout<<deck[pl.hand[i]].Honor[0]<<deck[pl.hand[i]].Honor[1]<<' '<<std::endl;
    }
}

int main()
{
	// Providing a seed value
	srand((unsigned) time(NULL));
    const size_t numberOfCardsInDeck = 52;
    Card deck[52] = {
        {HEARTS, RED, '2'}, {HEARTS, RED, '3'}, {HEARTS, RED, '4'},
        {HEARTS, RED, '5'}, {HEARTS, RED, '6'}, {HEARTS, RED, '7'},
        {HEARTS, RED, '8'}, {HEARTS, RED, '9'}, {HEARTS, RED, '1','0'},
        {HEARTS, RED, 'J'}, {HEARTS, RED, 'Q'}, {HEARTS, RED, 'K'},
        {HEARTS, RED, 'A'},
        {DIAMONDS, RED, '2'}, {DIAMONDS, RED, '3'}, {DIAMONDS, RED, '4'},
        {DIAMONDS, RED, '5'}, {DIAMONDS, RED, '6'}, {DIAMONDS, RED, '7'},
        {DIAMONDS, RED, '8'}, {DIAMONDS, RED, '9'}, {DIAMONDS, RED, '1','0'},
        {DIAMONDS, RED, 'J'}, {DIAMONDS, RED, 'Q'}, {DIAMONDS, RED, 'K'},
        {DIAMONDS, RED, 'A'},
        {CLUBS, BLACK, '2'}, {CLUBS, BLACK, '3'}, {CLUBS, BLACK, '4'},
        {CLUBS, BLACK, '5'}, {CLUBS, BLACK, '6'}, {CLUBS, BLACK, '7'},
        {CLUBS, BLACK, '8'}, {CLUBS, BLACK, '9'}, {CLUBS, BLACK, '1','0'},
        {CLUBS, BLACK, 'J'}, {CLUBS, BLACK, 'Q'}, {CLUBS, BLACK, 'K'},
        {CLUBS, BLACK, 'A'},
        {SPADES, BLACK, '2'}, {SPADES, BLACK, '3'}, {SPADES, BLACK,'4'},
        {SPADES, BLACK, '5'}, {SPADES, BLACK, '6'}, {SPADES, BLACK,'7'},
        {SPADES, BLACK, '8'}, {SPADES, BLACK, '9'}, {SPADES, BLACK, '1','0'},
        {SPADES, BLACK, 'J'}, {SPADES, BLACK, 'Q'}, {SPADES, BLACK, 'K'},
        {SPADES, BLACK, 'A'}
    };
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
    PrintHand(player1,deck,numberOfCardsInDeck);
    std::cout<<std::endl;
    PrintHand(player2,deck,numberOfCardsInDeck);
    std::cout<<std::endl;
    PrintHand(player3,deck,numberOfCardsInDeck);
    std::cout<<std::endl;
    PrintHand(player4,deck,numberOfCardsInDeck);
    return 0;
}