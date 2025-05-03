#include "Fixed.hpp"
#include <iostream>


int main( void ) {
Fixed a;
a.setRawBits(420);
Fixed b( a );
Fixed c;
c.setRawBits(2137);
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}
