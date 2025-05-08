#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "This ClapTrap is a ScavTrap" << std::endl;
	this->_hp = 100;
	this->_energy = 50;
	this->_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
	*this = src;
	std::cout << "ScavTrap copy constructor called on " << src._name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src){
	if (this == &src)
		return (*this);
	this->_name = src._name;
	this->_hp = src._hp;
	this->_energy = src._energy;
	this->_dmg = src._dmg;
	std::cout << "ScavTrap assigment constructor called on " << src._name << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	if (0 == this->_hp)
		std::cout << "ScavTrap " << this->_name << " has no hp left to attack" << std::endl;
	else if (0 == this->_energy)
		std::cout << "ScavTrap " << this->_name << " has no energy left to attack" << std::endl;
	else {
		this->_energy--;
		std::cout <<
			"ScavTrap " <<
			this->_name <<
			" attacks " <<
			target <<
			", causing " <<
			this->_dmg <<
			" points of damage!" <<
			std::endl;
	}
}

void	ScavTrap::guardGate(){
	if (this->_hp == 0)
		std::cout << this->_name << " has no hp left to change into gatekeeper mode" << std::endl;
	else
		std::cout << this->_name << " is now in gatekeeper mode" << std::endl;
}
