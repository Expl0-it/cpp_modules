#include "ArgCheck.hpp"
#include "RPN.hpp"

int main (int argc, char *argv[]) {
	if (false == ArgCheck::checkArgCount(argc, 2))
		return (1);

	try {
		RPN rpn;
		if (false == rpn.compute(static_cast<std::string>(argv[1])))
			return (2);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (3);
	}

	return 0;
}
