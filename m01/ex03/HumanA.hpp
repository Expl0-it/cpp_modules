#pragma once

#include "Weapon.hpp"

class HumanA{
private:
	std::string	_name;
	Weapon _wpn;
	HumanA();

public:
	HumanA(std::string name, Weapon wpn);
	~HumanA();
	void	setWeapon(Weapon);
	void	attack() const;
};
