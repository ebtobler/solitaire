#include <iostream>
#include "Card.h"


// prints the initial board setup
/*
 ff | bb | bb | bb | bb | bb | bb | cc
    | ff | bb | bb | bb | bb | bb | dd
    |    | ff | bb | bb | bb | bb | hh
    |    |    | ff | bb | bb | bb | ss
    |    |    |    | ff | bb | bb |
    |    |    |    |    | ff | bb |
    |    |    |    |    |    | ff |
*/
void printSetup() {
    for (int row = 0; row < 7; row++) {  // 7 rows of cards
        for (int pad = 0; pad < row; pad++) {  // prints the padding cells
            std::cout << "    |";
        }
        Card c = Card(13, 2);
        std::cout << " " << c.cardstr() << " |";
        for (int blanks = 0; blanks < 6 - row; blanks++) {  // prints blank cards in next columns
            std::cout << " " << blank() << " |";
        }
        std::cout << "\n";
    }
    for (int i = 1; i <= 7; i++) {
        std::cout << " C" << i << " |";
    }
    std::cout << "\n\n";
}


int main(int argc, char *argv[]) {
    for (int s = 0; s < 4; s++) {
        for (int v = 0; v < 14; v++) {
            Card c(v, s);
            //c.printcard();
            //std::cout << " | ";
            std::cout << c.cardstr() << " | ";
        }
        std::cout << "\n";
    }
    Card c(1, 3); // ace of spades
    std::cout << "\n" << c.to_string() << "\n";
    c.printcard();
    std::cout << "\n\n";

    for (int s = 0; s < 14; s++) {
        std::cout << blank() << " | ";
    }
    std::cout << "\n\n";
    printSetup();
}
