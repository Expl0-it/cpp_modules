#include "whatever.hpp"
#include <iostream>

int main(void) {
	{
		int a = 5, b = 10, c = -2;
		float x = 6.9f, y = 21.37f, z = -3.1415f;

		std::cout << min(a, c) << std::endl;
		swap(b, c);
		std::cout << min(a, c) << std::endl;
		std::cout << max(a, c) << std::endl;

		std::cout << min(x, z) << std::endl;
		swap(y, z);
		std::cout << min(x, z) << std::endl;
		std::cout << max(x, z) << std::endl;
	}
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
}
