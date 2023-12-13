#include "Card.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>


// Card constructor
//  value: number 0-13 indicating the value of the card
//  suit: number 0-3 indicating the suit of the card
Card::Card(char v, char s) {
    value = v;
    suit = s;
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


// prints the card 
//  three characters - two for value, one for suit
//  text color will correspond to card color
void Card::printcard() {
    std::string v;
    if (value > 10) {
        switch(value) {
            case 11:
                v = "J";
                break;
            case 12:
                v = "Q";
                break;
            case 13:
                v = "K";
                break;
            default:
                v = " ";
                break;
        }
    } else if (value == 10) {
        //v = std::to_string(value);
        v = "X";
    } else {
        //v = " " + std::to_string(value);
        v = std::to_string(value);
    }
    std::string s;
    switch(suit) {
        case 0:
            s = "♣";
            break;
        case 1:
            s = "♢";
            break;
        case 2:
            s = "♡";
            break;
        case 3:
            s = "♠";
            break;
        default:
            s = " ";
            break;
    }

    std::string outstr = v + s;

    //  manages print color 
    //  format: starts with \033 (escape char) followed by [
    //          after that are numbers separated by ; and terminated by 'm'
    //          47 = white background, 31 = red text, 
    if (color == 0) {  // black
        std::cout << "\033[47;30m";
    } else if (color == 1) {  // red
        std::cout << "\033[47;31m";
    }
    std::cout << std::setfill(' ') << std::setw(3) << outstr << "\033[0m";
}