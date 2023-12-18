#include "Card.h"

#ifndef DECK_H
#define DECK_H
class Deck {
    private:
        Card *deck;

    public:
        int size;
        Deck();
        Card *draw();
        void shuffle(unsigned int seed);
};
#endif // DECK_H
