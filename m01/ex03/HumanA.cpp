#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wpn) : _name(name), _wpn(&wpn){
	std::cout << "HumanA: " << _name << " holds a: " << _wpn->getType() << std::endl;
}

	HumanA::~HumanA(){
	std::cout << "HumanA: " << _name << " destroyed" << std::endl;
}

void	HumanA::setWeapon(Weapon wpn){
	this->_wpn = &wpn;
}

void	HumanA::attack() const{
	std::cout << this->_name << " attacks with their " << this->_wpn->getType() << std::endl;
}
