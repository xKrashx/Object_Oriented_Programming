#include <iostream>
#include "Card.hpp"

void enterCard(Card& card) 
{
    char buffer[MAX_BUFF_SIZE];
    std::cin.getline(buffer, MAX_BUFF_SIZE);
    char firstInput = buffer[0], secondInput = buffer[1];
    if (firstInput >= '2' && firstInput <= '9') 
    {
        card.isSmall = true;
        card.small = firstInput - '0';
    } 
    else 
    {
        card.isSmall = false;
        switch (firstInput) 
        {
            case 'J':
                card.honor = J;
                break;
            case 'Q':
                card.honor = Q;
                break;
            case 'K':
                card.honor = K;
                break;
            case 'A':
                card.honor = A;
                break;
        }
    }

    switch (secondInput) 
    {
        case 'S':
            card.s = SPADES;
            card.c = BLACK;
            break;
        case 'H':
            card.s = HEARTS;
            card.c = RED;
            break;
        case 'D':
            card.s = DIAMONDS;
            card.c = RED;
            break;
        case 'C':
            card.s = CLUBS;
            card.c = BLACK;
            break;
    }

}

void printCard(const Card& card) 
{
    if (card.isSmall) 
    {
        std::cout << card.small;
    } 
    else
    {
        switch (card.honor) 
        {
            case J:
                std::cout << "Jack";
                break;
            case Q:
                std::cout << "Queen";
                break;
            case K:
                std::cout << "King";
                break;
            case A:
                std::cout << "Ace";
                break;
        }
    }

    std::cout << " of ";

    switch (card.s) 
    {
        case SPADES:
            std::cout << "spades";
            break;
        case HEARTS:
            std::cout << "hearts";
            break;
        case DIAMONDS:
            std::cout << "diamonds";
            break;
        case CLUBS:
            std::cout << "clubs";
            break;
    }

    std::cout << std::endl;
}