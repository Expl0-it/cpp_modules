#include "Zombie.hpp"

int	main(void){
	
	int	n = 0;

	Zombie *z = zombieHorde(n, "Bob");

	n = 5;

	z = zombieHorde(n, "Jeff");
	if (NULL == z)
		return (-1);

	for (int i = 0; i < n; i++) {
		z[i].announce();
	}

	delete[] z;
	return 0;
}
