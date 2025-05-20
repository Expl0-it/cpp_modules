#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const& src) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal& AAnimal::operator=(AAnimal const& src) {
	std::cout << "AAnimal assigment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType() const {
	return (this->_type);
}
