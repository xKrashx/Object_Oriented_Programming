#include <iostream>
#include <cstring>

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

struct Deck {
    Card cards[MAX_DECK_SIZE] = 
    {
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
};

struct Player {
    char name[MAX_BUFF_SIZE];
    Card hand[MAX_HAND_SIZE];
    int size = 0;
};


void dealSinglePlayer(Deck& deck, Player& p) {
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


int main() {
    Deck deck;
    Player p1, p2, p3, p4;
    Player players[] = {p1, p2, p3, p4};
    const short numPlayers = sizeof(players) / sizeof(players[0]);
    for (int i = 0; i < numPlayers; i++)
    {
        std::cout << "Enter player " << i + 1 << " name: ";
        std::cin.getline(players[i].name, MAX_BUFF_SIZE);
    }
    for (int i = 0; i < numPlayers; i++) 
    {
        dealSinglePlayer(deck, players[i]);
    }
    for (int i = 0; i < numPlayers; i++) 
    {
        showHand(players[i]);
    }
    return 0;
}