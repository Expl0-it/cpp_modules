#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern&			Intern::operator=(const Intern& src)
{
	(void)src;
	std::cout << "Intern assigment constructor called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget) const {
	// TODO: Implement makeForm
}

AForm*	Intern::_makeShrubberyCreationForm(std::string formTarget) const {
	return (new ShrubberyCreationForm(formTarget));
}

AForm*	Intern::_makeRobotomyRequestForm(std::string formTarget) const {
	return (new RobotomyRequestForm(formTarget));
}

AForm*	Intern::_makePresidentialPardonForm(std::string formTarget) const {
	return (new PresidentialPardonForm(formTarget));
}
