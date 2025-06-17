#include "Weapon.hpp"

Weapon::Weapon() : _type("Default Weapon"){
	std::cout << "Default weapon created" << std::endl;
}

Weapon::Weapon(std::string type) : _type(type){
	std::cout << "Weapon of type: " << _type << " created" << std::endl;
}
Weapon::~Weapon(){
	std::cout << "Weapon: " << _type <<  " destroyed" << std::endl;
}

const std::string&	Weapon::getType(void) const{
	return (this->_type);
}
void	Weapon::setType(std::string newType){
	this->_type = newType;
}
