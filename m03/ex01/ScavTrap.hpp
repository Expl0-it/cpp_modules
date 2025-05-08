#pragma  once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &assign);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();

private:
	ScavTrap();
};
