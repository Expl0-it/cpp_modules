#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
public:
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	~Dog();

	void	makeSound() const;
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
