#include <iostream>
#include "Card.h"


int main(int argc, char *argv[]) {
    for (int s = 0; s < 4; s++) {
        for (int v = 0; v < 14; v++) {
            Card c(v, s);
            c.printcard();
        }
    }
    Card c(1, 3); // ace of spades
    std::cout << c.tostring() << "\n";
    c.printcard();
}
