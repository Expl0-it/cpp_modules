#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main () {

	ScavTrap o1("Finn");
	ScavTrap o2("Jake");

	ScavTrap o3 = o2;
	ScavTrap o4(o1);

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
	o2.guardGate();
	o2.takeDamage(1000);
	o2.guardGate();
	o1.beRepaired(15);
	return 0;
}
