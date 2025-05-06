#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _dmg(0) {
	std::cout << "Name constructor called with name: " << _name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	if (0 == this->_hp)
		std::cout << "ClapTrap " << this->_name << " has no hp left to attack" << std::endl;
	else if (0 == this->_energy)
		std::cout << "ClapTrap " << this->_name << " has no energy left to attack" << std::endl;
	else {
		this->_energy--;
		std::cout <<
			"ClapTrap " <<
			this->_name <<
			" attacks " <<
			target <<
			", causing " <<
			this->_dmg <<
			" points of damage!" <<
			std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (0 == this->_hp)
		std::cout << "ClapTrap " << this->_name << " has 0hp already" << std::endl;
	else if (amount >= this->_hp) {
		std::cout << "ClapTrap's " << this->_name << " hp falls to 0" << std::endl;
		this->_hp = 0;
	}
	else {
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage" << std::endl;
		this->_hp -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (0 == this->_hp)
		std::cout << "ClapTrap " << this->_name << " has no hp left to heal itself" << std::endl;
	else if (0 == this->_energy)
		std::cout << "ClapTrap " << this->_name << " has no energy left to heal itself" << std::endl;
	else {
		this->_energy--;
		this->_hp += amount;
		std::cout <<
			"ClapTrap " <<
			this->_name <<
			" repaires itself for " <<
			amount <<
			" hp, now it has " <<
			this->_hp <<
			" hp" <<
			std::endl;
	}
}
