#include "Card.h"
#include <iostream>
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


void Card::printval() {
    switch(value) {
        case 0:  // joker
            printf("%c", '!');
            break;
        case 1:  // ace
            printf("%c", 'A');
            break;
        case 2:
            printf("%c", '2');
            break;
        case 3:
            printf("%c", '3');
            break;
        case 4:
            printf("%c", '4');
            break;
        case 5:
            printf("%c", '5');
            break;
        case 6:
            printf("%c", '6');
            break;
        case 7:
            printf("%c", '7');
            break;
        case 8:
            printf("%c", '8');
            break;
        case 9:
            printf("%c", '9');
            break;
        case 10:
            printf("%c", '1');
            break;
        case 11:  // jack
            printf("%c", 'J');
            break;
        case 12:  // queen
            printf("%c", 'Q');
            break;
        case 13:  // king
            printf("%c", 'K');
            break;
        default:
            printf(" ");
            break;
    }
}


void Card:: printsuit() {
    switch(suit) {
    case 0:  // clubs
        printf("♣");
        break;
    case 1:  // diamonds
        printf("♢");
        break;
    case 2:  // hearts
        printf("♡");
        break;
    case 3:  // spades
        printf("♠");
        break;
    default:
        printf(" ");
        break;
    }

}


void Card::printcard() {
      /*" ____________ \n"  // 0-14
        "|v          s|\n"  // 15-29
        "|            |\n"  // 30-44
        "|            |\n"  // 45 - 59
        "|            |\n"  // 60 - 74
        "|            |\n"  // 75 - 89
        "|            |\n"  // 90 - 104
        "|            |\n"  // 105 - 119
        "|s__________v|\n"; // 120 - 134*/
    printf(" ____________ \n");
    printf("|");
    printval();
    printf("          ");
    printsuit();
    printf("|\n");
    printf("|            |\n|            |\n|            |\n|            |\n|            |\n|            |\n");
    printf("|");
    printsuit();
    printf("__________");
    printval();
    printf("|\n");
        
}

