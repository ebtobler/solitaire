#include <iostream>

namespace sol {
    int print(int n) {
        printf("%d\n", n);
        return n;
    }
}


using namespace sol;
int main(int argc, char *argv[]) {
    printf("in solitaire\n");
    sol::print(10);
}