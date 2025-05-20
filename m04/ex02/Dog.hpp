#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
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

// class AAnimal {
// public:
// 	AAnimal();
// 	AAnimal(const AAnimal &src);
// 	AAnimal &operator=(const AAnimal &src);
// 	~AAnimal();
//
// 	virtual void	makeSound() const;
//
// protected:
// 	std::string _type;
//
// private:
//
// };
