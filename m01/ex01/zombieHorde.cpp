#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name){
	if (N <= 0)
	{
		std::cout << "N cannot be smaller than 1" << std::endl;
		return (NULL);
	}

	Zombie *z = new Zombie[N];
	if (NULL == z)
		return (NULL);
	
	for (int i = 0; i < N; i++) {
		z[i].setName(name);
	}

	return (z);
}
