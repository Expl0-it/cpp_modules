#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:
	WrongCat();
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &src);
	~WrongCat();

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
