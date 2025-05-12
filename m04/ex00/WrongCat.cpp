#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& src) : WrongAnimal() {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=(WrongCat const& src) {
	std::cout << "WrongCat assigment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "WrongCat: Meow Meow" << std::endl;
}
