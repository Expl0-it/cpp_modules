#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main () {

	FragTrap o1("Finn");
	FragTrap o2("Jake");

	FragTrap o3 = o2;
	FragTrap o4(o1);

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
	o2.highFivesGuys();
	o2.takeDamage(1000);
	o2.highFivesGuys();
	o1.beRepaired(15);
	return 0;
}
