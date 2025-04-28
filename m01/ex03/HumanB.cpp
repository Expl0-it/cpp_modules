#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _wpn(NULL){
	std::cout << "HumanB: " << _name << " doesn't hold a weapon" << std::endl;
}

HumanB::HumanB(std::string name, Weapon &wpn) : _name(name), _wpn(&wpn){
	std::cout << "HumanB: " << _name << " holds a: " << _wpn->getType() << std::endl;
}

	HumanB::~HumanB(){
	std::cout << "HumanB: " << _name << " destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon &wpn){
	this->_wpn = &wpn;
}

void	HumanB::attack() const{
	if (!this->_wpn)
		std::cout << this->_name << " cannot attack with no weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_wpn->getType() << std::endl;
}
