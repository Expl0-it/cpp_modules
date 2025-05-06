#include "ClapTrap.hpp"

int main () {

	ClapTrap o1("Finn");
	ClapTrap o2("Jake");

	o1.attack("Jake");
	o2.takeDamage(10);
	o2.attack("Finn");
	o2.beRepaired(10);
	o1.beRepaired(15);
	o1.attack("Jake");
	o1.attack("Jake");
	o1.attack("Jake");
	o1.attack("Jake");
	o1.attack("Jake");
	o1.attack("Jake");
	o1.attack("Jake");
	o1.attack("Jake");
	o1.attack("Jake");
	o1.beRepaired(15);
	return 0;
}
