#include <iostream>
#include "../include/polymorph-lib.h"

int main() {
    std::cout << "int    " << poly_int()    << std::endl;
    std::cout << "uint   " << poly_uint()   << std::endl;
    std::cout << "ll     " << poly_ll()     << std::endl;
    std::cout << "ull    " << poly_ull()    << std::endl;
    std::cout << "float  " << poly_float()  << std::endl;
    std::cout << "double " << poly_double() << std::endl;
}