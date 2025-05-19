#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const& src) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = src;
}

Dog& Dog::operator=(Dog const& src) {
	std::cout << "Dog assigment operator called" << std::endl;
	if (this != &src) {
		this->_type = src._type;
		*(this->_brain) = *(src._brain);
	}
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Bark Bark" << std::endl;
}

std::string	Dog::getIdea(unsigned int index) const {
	return (this->_brain->getIdea(index));
}
