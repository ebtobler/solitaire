#include "Card.h"

#ifndef DECK_H
#define DECK_H
class Deck {
    private:
        Card deck[52];

    public:
        int size;
        Deck();
        Card *draw();
};
#endif // DECK_H
