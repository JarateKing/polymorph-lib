#include <iostream>
#include "../include/polymorph-lib.h"

int main() {
	std::cout << "int    " << poly_int() << '\n';
	std::cout << "uint   " << poly_uint() << '\n';
	std::cout << "ll     " << poly_ll() << '\n';
	std::cout << "ull    " << poly_ull() << '\n';
	std::cout << "float  " << poly_float() << '\n';
	std::cout << "double " << poly_double() << '\n';
}