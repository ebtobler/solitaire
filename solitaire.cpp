#include <iostream>
#include "Card.h"
#include "Deck.h"


// struct to represent game state_t
typedef struct state {
    Deck deck;              // deck to draw from
    Card *stacks[7][13];     // represents each stack of cards
    char revealed[7][6];    // boolean that signifies if card has been revealed or not
    char win;
} state_t;


// initializes the game and returns a handle to the game state_t
state_t *game_init(unsigned int seed = 0) {
    state_t *handle = (state_t *) malloc(sizeof(state_t));
    if (handle == NULL) {
        std::cerr << "Game state_t handle malloc failed\n";
        return NULL;
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
    handle->win = 0;
    return handle;
}


// prints state_t of given state_t handle
void print_state_t(state_t *handle) {
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


// adds the current card in hand to specified stack (1-7)
void add(char stack) {
    
}


// moves the revealed cards on stack 1 onto stack 2
void move(char stack1, char stack2) {

}


// plays the card at the top of the specified stack
//  default 0 plays card in hand
void play(char stack = 0) {

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
    int seed;
    std::cout << "Type an integer seed for game setup: ";
    std::cin >> seed;
    std::cout << "\n\n";
    state_t *handle = game_init(seed);

    while (!handle->win) {
        print_state_t(handle);
        std::string cmd;
        std::cout << "Type a command: ";
        std::cin >> cmd;
        std::cout << cmd + "\n";
    }
    //printSetup();
}
