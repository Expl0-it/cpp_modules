#include "HumanB.hpp"

	std::string	_name;
	Weapon _wpn;

HumanB::HumanB(std::string name) : _name(name){
	std::cout << "HumanB: " << _name << " doesn't hold a weapon" << std::endl;
}

HumanB::HumanB(std::string name, Weapon wpn) : _name(name), _wpn(wpn){
	std::cout << "HumanB: " << _name << " holds a: " << _wpn.getType() << std::endl;
}

	HumanB::~HumanB(){
	std::cout << "HumanB destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon wpn){
	this->_wpn = wpn;
}

void	HumanB::attack() const{
	std::cout << this->_name << " attacks with their " << this->_wpn.getType() << std::endl;
}
