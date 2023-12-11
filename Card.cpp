#include "Card.h"
#include <iostream>
#include <string>
#include <stdio.h>


// Card constructor
//  value: number 0-13 indicating the value of the card
//  suit: number 0-3 indicating the suit of the card
Card::Card(char value, char suit) {
    value = value;
    suit = suit;
    switch(value) {  // initialize name field based on value
        case 0:
            valName = "Joker";
            break;
        case 1:
            valName = "ace";
            break;
        case 2:
            valName = "two";
            break;
        case 3:
            valName = "three";
            break;
        case 4:
            valName = "four";
            break;
        case 5:
            valName = "five";
            break;
        case 6:
            valName = "six";
            break;
        case 7:
            valName = "seven";
            break;
        case 8:
            valName = "eight";
            break;
        case 9:
            valName = "nine";
            break;
        case 10:
            valName = "ten";
            break;
        case 11:
            valName = "jack";
            break;
        case 12:
            valName = "queen";
            break;
        case 13:
            valName = "king";
            break;
        default:
            valName = "undef";
            break;
    }
    switch(suit) {
        case 0:
            suitName = "clubs";
            color = 0;
            break;
        case 1:
            suitName = "diamonds";
            color = 1;
            break;
        case 2:
            suitName = "hearts";
            color = 1;
            break;
        case 3:
            suitName = "spades";
            color = 0;
            break;
        default:
            suitName = "undef";
            color = -1;
            break;
    }
}

// converts card to string in format "%s of %s"
std::string Card::tostring() {
    char buffer[25];
    int size = 25;
    snprintf(buffer, size, "%s of %s", valName.c_str(), suitName.c_str());
    std::string ret = buffer;
    return ret;
}

std::string Card::graphcard() {
    char buffer[250];
    int size = 250;
    const char *draw = 
        " ____________ \n"
        "|A          \u2660|\n"
        "|            |\n"
        "|     /\\     |\n"
        "|    /__\\    |\n"
        "|   /    \\   |\n"
        "|            |\n"
        "|            |\n"
        "|\u2660__________A|\n";
    std::string ret = draw;
    return draw;
}

