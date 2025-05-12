#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const& src) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator=(Cat const& src) {
	std::cout << "Cat assigment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
