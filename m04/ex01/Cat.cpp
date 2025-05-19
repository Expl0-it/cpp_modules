#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const& src) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = src;
}

Cat& Cat::operator=(Cat const& src) {
	std::cout << "Cat assigment operator called" << std::endl;
	if (this != &src) {
		this->_type = src._type;
		*(this->_brain) = *(src._brain);
	}
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

std::string	Cat::getIdea(unsigned int index) const {
	return (this->_brain->getIdea(index));
}
