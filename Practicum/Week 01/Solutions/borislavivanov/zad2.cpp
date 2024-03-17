#include <iostream>
#include <cstring>

enum Suit{
    clubs,
    spades,
    diamonds,
    hearts
};

enum Color{
    red,
    black
};

const char * suits[] = {
    "clubs",
    "spades",
    "diamonds",
    "hearts"
};

const char * color[] = {
    "red",
    "black"
};

struct Card{
    Suit suit;
    Color color;
    char Honor;
};
 
int main(){
    const size_t inputLenght = 9;
    char input[inputLenght];
    Card newCard;
    std::cin.getline(input,inputLenght);
    for(size_t i=0;i< sizeof(suits)/sizeof(char*);i++)if(!strcmp(input,suits[i]))newCard.suit = (Suit)i;
    std::cin.getline(input,inputLenght);
    for(size_t i=0;i< sizeof(color)/sizeof(char*);i++)if(!strcmp(input,color[i]))newCard.color = (Color)i;
    std::cin.getline(input,inputLenght);
    newCard.Honor = input[0];
    std::cout<<suits[newCard.suit]<<' '<<color[newCard.color]<<' '<<newCard.Honor;
    
    return 0;
}