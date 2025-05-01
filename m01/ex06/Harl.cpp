#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Harl created" << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl destroyed" << std::endl;
}

void	Harl::complain(std::string level){
	switch (assignEnum(level)) {
		case hu::DEBUG:
			this->debug();
			__attribute__ ((fallthrough));
		case hu::INFO:
			this->info();
			__attribute__ ((fallthrough));
		case hu::WARNING:
			this->warning();
			__attribute__ ((fallthrough));
		case hu::ERROR:
			this->error();
			break ;
		default:
			std::cout << "Unknown level" << std::endl;
			break;
	}
}

hu::t_level	Harl::assignEnum(std::string level){
	if (level == "DEBUG")
		return (hu::DEBUG);
	if (level == "INFO")
		return (hu::INFO);
	if (level == "WARNING")
		return (hu::WARNING);
	if (level == "ERROR")
		return (hu::ERROR);
	return ((hu::t_level)-1);
}

void	Harl::debug(void){
	std::cout <<
	"[[ DEBUG ]]" << std::endl <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
	<< std::endl << std::endl;
}

void	Harl::info(void){
	std::cout <<
	"[[ INFO ]]" << std::endl <<
	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl << std::endl;

}

void	Harl::warning(void){
	std::cout <<
	"[[ WARNING ]]" << std::endl <<
	"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
	<< std::endl << std::endl;
}

void	Harl::error(void){
	std::cout <<
	"[[ ERROR ]]" << std::endl <<
	"This is unacceptable! I want to speak to the manager now."
	<< std::endl << std::endl;
}
