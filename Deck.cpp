#include <iostream>
#include "Deck.h"
#include "Card.h"

// Deck constructor
//  Initial order of the deck is as follows in ace to king order:
//  Clubs, diamonds, hearts, spades
Deck::Deck() {
    deck = (Card *) calloc(sizeof(Card), 52);
    for (int suit = 0; suit <= 3; suit++) {
        for (int value = 1; value <= 13; value++) {
            int index = (13 * suit) + (value - 1);
            Card c = Card(value, suit);
            deck[index].copyCard(c);
        }
    }
    size = 52;
}


// simulates drawing a card from the deck
//  Does not remove the card from the deck array,
//  simply moves the pointer to the top card, i.e.
//  the size of the deck
Card *Deck::draw() {
    size--;
    return &deck[size];
}


// shuffles the deck using a seed provided
void Deck::shuffle(unsigned int seed) {
    srand(seed);
    Card *shuffled = (Card *) calloc(sizeof(Card), 52);
    char filled[52] = {0};
    for (int suit = 0; suit <= 3; suit++) {
        for (int value = 1; value <= 13; value++) {
            int index = rand() % 52;
            while (filled[index]) {
                index++;
                if (index >= 52) {
                    index = 0;
                }
            }
            Card c = Card(value, suit);
            shuffled[index].copyCard(c);
            filled[index] = 1;
        }
    }
    deck = shuffled;
    size = 52;
}
