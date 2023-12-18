#include <iostream>
#include "Card.h"
#include "Deck.h"


// struct to represent game state
typedef struct state {
    Deck deck;              // deck to draw from
    Card *stacks[7][13];     // represents each stack of cards
    char revealed[7][6];    // boolean that signifies if card has been revealed or not
} state_t;


// initializes the game and returns a handle to the game state
state *game_init(unsigned int seed = 0) {
    state *handle = (state *) malloc(sizeof(state));
    if (handle == NULL) {
        std::cerr << "Game state handle malloc failed\n";
    }
    Deck deck = Deck();
    if (seed != 0) {
        deck.shuffle(seed);
    }
    handle->deck = deck;
    for (int stack = 0; stack < 7; stack++) {
        for (int n = 0; n < 6; n++) {  // initializes all the revealed booleans to -1 indicating empty
            handle->revealed[stack][n] = -1;
        }
        for (int n = 0; n < stack + 1; n++) {  // intializes the cards in the stack from the deck
            handle->stacks[stack][n] = handle->deck.draw();
            handle->revealed[stack][n] = 0;
            if (n == stack) {
                handle->revealed[stack][n] = 1;  // if final card in stack, set revealed
            }
        }
    }
    return handle;
}


// prints state of given state handle
void print_state(state *handle) {
    for (int row = 0; row < 13; row++) {  // for each row

        char cont = 0;
        for (int s = 0; s < 7; s++) {  // check if row is empty - if it is, no need to print further rows
            if (handle->stacks[s][row] != NULL) {
                cont = 1;
            }
        }
        if (cont == 0) {
            break;
        }

        for (int stack = 0; stack < 7; stack++) {  // print card at index 'row' in stack 'stack' 
            
            char revealed = -1;  // default status is empty cell
            if (handle->stacks[stack][row] != NULL) {  // if a card exists, set default to revealed
                revealed = 1;
            }
            if (row < 6) {
                revealed = handle->revealed[stack][row];  // check if card is revealed or not
            }

            if (revealed == -1) {  // empty cell
                std::cout << "   ";
            } else if (revealed == 0) {  // facedown 
                std::cout << " " << blank();
            } else if (revealed == 1) {  // revealed/faceup
                std::cout << " " << handle->stacks[stack][row]->cardstr();
            }
            std::cout << " |";
        }

        // prints card piles 
        if (row == 0) {
            Card clubs = Card(0, 0);
            std::cout << " " << clubs.cardstr();
        } else if (row == 2) {
            Card diamonds = Card(0, 1);
            std::cout << " " << diamonds.cardstr();
        } else if (row == 4) {
            Card hearts = Card(0, 2);
            std::cout << " " << hearts.cardstr();
        } else if (row == 6) {
            Card spades = Card(0, 3);
            std::cout << " " << spades.cardstr();
        }

        std::cout << "\n";
    }
    for (int i = 1; i <= 7; i++) {
        std::cout << " C" << i << " |";
    }
    std::cout << "\n\n";
}


// prints the initial board setup for reference/debugging
/*
 ff | bb | bb | bb | bb | bb | bb | cc
    | ff | bb | bb | bb | bb | bb |
    |    | ff | bb | bb | bb | bb | dd
    |    |    | ff | bb | bb | bb |
    |    |    |    | ff | bb | bb | hh
    |    |    |    |    | ff | bb |
    |    |    |    |    |    | ff | ss
 C1 | C2 | C3 | C4 | C5 | C6 | C7 |
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
        if (row == 0) {
            Card clubs = Card(0, 0);
            std::cout << " " << clubs.cardstr();
        } else if (row == 2) {
            Card diamonds = Card(0, 1);
            std::cout << " " << diamonds.cardstr();
        } else if (row == 4) {
            Card hearts = Card(0, 2);
            std::cout << " " << hearts.cardstr();
        } else if (row == 6) {
            Card spades = Card(0, 3);
            std::cout << " " << spades.cardstr();
        }
        std::cout << "\n";
    }
    for (int i = 1; i <= 7; i++) {
        std::cout << " C" << i << " |";
    }
    std::cout << "\n\n";
}


int main(int argc, char *argv[]) {
    
    /*for (int s = 0; s < 4; s++) {
        for (int v = 0; v < 14; v++) {
            Card c(v, s);
            //c.printcard();
            //std::cout << " | ";
            std::cout << c.cardstr() << " | ";
        }
        std::cout << "\n";
    }
    for (int s = 0; s < 14; s++) {
        std::cout << blank() << " | ";
    }
    Deck deck = Deck();
    while (deck.size > 0) {
        Card *card = deck.draw();
        std::cout << card->cardstr() << " | ";
        if (deck.size % 13 == 0) {
            std::cout << "\n";
        }
    }*/
    std::cout << "\n\n";
    state *handle = game_init(2);
    print_state(handle);
    //printSetup();
}
