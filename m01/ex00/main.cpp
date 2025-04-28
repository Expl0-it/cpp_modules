#include "Zombie.hpp"

int	main(void){
	
	{
	randomChump("Bob");
	Zombie *jeff = newZombie("Jeff");
	jeff->announce();
	delete jeff;
	}

	return 0;
}
