#pragma  once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &assign);
	~FragTrap();

	void	attack(const std::string& target);
	void	highFivesGuys();

private:
	FragTrap();
};
