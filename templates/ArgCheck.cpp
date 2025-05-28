#include "ArgCheck.hpp"

bool	ArgCheck::checkArgCount(int argc, int expected){
	if (argc != expected)
	{
		std::cout << "Error: Wrong argument count" << std::endl;
		return (false);
	}
	return (true);
}
