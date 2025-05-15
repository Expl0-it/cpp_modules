#pragma once

#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &src);
	~WrongAnimal();

	void	makeSound() const;
	std::string		getType() const;

protected:
	std::string _type;

private:

};
