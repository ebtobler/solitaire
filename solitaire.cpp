#include <iostream>
#include "Card.h"

namespace sol {
    int print(int n) {
        printf("%d\n", n);
        return n;
    }
}


using namespace sol;
int main(int argc, char *argv[]) {
    Card c(1, 3); // ace of spades
    std::cout << c.tostring() << "\n";
    std::cout << c.graphcard() << "\n";
}
