#include "Deck.h"
#include "Card.h"


// Deck constructor
//  Initial order of the deck is as follows in ace to king order:
//  Clubs, diamonds, hearts, spades
Deck::Deck() {
    for (int suit = 0; suit <= 3; suit++) {
        for (int value = 1; value <= 13; value++) {
            int index = (13 * suit) + (value - 1);
            deck[index] = Card(value, suit);
        }
    }
    size = 52;
}


// simulates drawing a card from the deck
//  Does not remove the card from the deck array,
//  simply moves the pointer to the top card, i.e.
//  the size of the deck
Card Deck::draw() {
    size--;
    return deck[size];
}
