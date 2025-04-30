#include "Harl.hpp"

int main () {

	Harl harl;
	std::cout << std::endl << std::endl;

	std::cout << "Harl debug: " << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << std::endl;

	std::cout << "Harl info: " << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << std::endl;

	std::cout << "Harl warning: " << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << std::endl;

	std::cout << "Harl error: " << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << std::endl;

	std::cout << "Harl random unmatching value: " << std::endl;
	harl.complain("UNMATCHING");
	std::cout << std::endl << std::endl;

	return 0;
}
