#pragma once

#include "Animal.hpp"

class Dog : public Animal{
public:
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	~Dog();

	void	makeSound() const;

private:
	
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
