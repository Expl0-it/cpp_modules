#include "Harl.hpp"
#include "ArgCheck.hpp"

int main (int argc, char **argv) {

	if (false == ArgCheck::checkArgCount(argc, 2))
		return (1);

	Harl harl;
	harl.complain(argv[1]);

	return 0;
}
