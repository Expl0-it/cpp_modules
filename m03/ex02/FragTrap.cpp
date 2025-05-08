#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "This ClapTrap is a FragTrap" << std::endl;
	this->_hp = 100;
	this->_energy = 100;
	this->_dmg = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	*this = src;
	std::cout << "FragTrap copy constructor called on " << src._name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &src){
	if (this == &src)
		return (*this);
	this->_name = src._name;
	this->_hp = src._hp;
	this->_energy = src._energy;
	this->_dmg = src._dmg;
	std::cout << "FragTrap assigment constructor called on " << src._name << std::endl;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target){
	if (0 == this->_hp)
		std::cout << "FragTrap " << this->_name << " has no hp left to attack" << std::endl;
	else if (0 == this->_energy)
		std::cout << "FragTrap " << this->_name << " has no energy left to attack" << std::endl;
	else {
		this->_energy--;
		std::cout <<
			"FragTrap " <<
			this->_name <<
			" attacks " <<
			target <<
			", causing " <<
			this->_dmg <<
			" points of damage!" <<
			std::endl;
	}
}

void	FragTrap::highFivesGuys(){
	if (this->_hp == 0)
		std::cout << this->_name << " has no hp left to request high fives" << std::endl;
	else
		std::cout << this->_name << " request high fives" << std::endl;
}
