#include "iter.hpp"
#include "help.hpp"

int main(void) {
	{
		int	ints[] = {1, 2 ,3 ,4};
		iter(ints, 4, print<int>);
		std::cout << std::endl;
		iter(ints, 4, increment<int>);
		iter(ints, 4, print<int>);
		std::cout << std::endl;

		char chars[] = {'A', 'b', 'C', 'd'};
		iter(chars, 4, print<char>);
		std::cout << std::endl;
		iter(chars, 4, increment<char>);
		iter(chars, 4, print<char>);
	}
}
