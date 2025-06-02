#pragma once
#include <iostream>
//#include <map>

class Harl {

public:
	Harl();
	~Harl();

	void	complain(std::string level);

private:
	// std::map<std::string, void (Harl::*)(void)>	levels;

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};
