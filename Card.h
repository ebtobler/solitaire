#include <string>

#ifndef CARD_H
#define CARD_H
class Card {
    private:
    std::string valName;    // name of the card
    std::string suitName;   // name of suit
    char value;         // 0 is Joker, 1-10 are literal, 11 = Jack, 12 = Queen, 13 = King
    char suit;          // 0 is clubs, 1 is diamonds, 2 is hearts, 3 is spades 
    char color;         // 0 is black, 1 is red
    void printval();
    void printsuit();

    public:
        Card(char v, char s);
        std::string tostring();
        void printcard();
};
#endif // CARD_H