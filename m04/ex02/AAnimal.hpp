#pragma once

#include <iostream>

class AAnimal {
public:
	AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &src);
	virtual ~AAnimal();

	virtual void	makeSound() const = 0;

	std::string		getType() const;

protected:
	std::string _type;

private:

};
