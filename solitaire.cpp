#include <iostream>
#include "Card.h"


int main(int argc, char *argv[]) {
    for (int s = 0; s < 4; s++) {
        for (int v = 0; v < 14; v++) {
            Card c(v, s);
            c.printcard();
            std::cout << " | ";
        }
        std::cout << "\n";
    }
    Card c(1, 3); // ace of spades
    std::cout << "\n" << c.tostring() << "\n";
    c.printcard();
}
