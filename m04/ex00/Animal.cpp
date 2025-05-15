#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const& src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal& Animal::operator=(Animal const& src) {
	std::cout << "Animal assigment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void		Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType() const {
	return (this->_type);
}
