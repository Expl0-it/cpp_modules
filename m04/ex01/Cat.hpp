#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	~Cat();

	void		makeSound() const;
	std::string	getIdea(unsigned int index) const;

private:
	Brain*	_brain;

};

// class Animal {
// public:
// 	Animal();
// 	Animal(const Animal &src);
// 	Animal &operator=(const Animal &src);
// 	~Animal();
//
// 	virtual void	makeSound() const;
//
// protected:
// 	std::string _type;
//
// private:
//
// };
