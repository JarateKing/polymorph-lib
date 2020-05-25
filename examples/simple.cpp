#include <iostream>
#include "../include/polymorph-lib.h"

int main() {
    // print out random number "0 <= x < 10000"
    // this number will only change when you recompile
    std::cout << poly_random(10000) << '\n';
}