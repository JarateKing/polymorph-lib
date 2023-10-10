#include <iostream>
#include "../include/polymorph-lib.h"

int main() {
    // Generate and print a random number between 0 and 9999 (inclusive).
    // This number will remain the same until the program is recompiled.
    int random_number = poly_random(10000);
    std::cout << "Random Number: " << random_number << '\n';
    return 0;
}
