#include "ScalarConverter.hpp"
#include "ArgCheck.hpp"

int main (int argc, char *argv[]) {
	if (false == ArgCheck::checkArgCount(argc, 2))
		return (-1);
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}
