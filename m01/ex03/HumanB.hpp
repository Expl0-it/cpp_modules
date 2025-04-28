#pragma once

#include "Weapon.hpp"

class HumanB{
private:
	std::string	_name;
	Weapon *_wpn;
	HumanB();

public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon &wpn);
	~HumanB();
	void	setWeapon(Weapon &wpn);
	void	attack() const;
};
