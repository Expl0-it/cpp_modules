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

static AForm*	_makeShrubberyCreationForm(std::string formTarget) {
	return (new ShrubberyCreationForm(formTarget));
}

static AForm*	_makeRobotomyRequestForm(std::string formTarget) {
	return (new RobotomyRequestForm(formTarget));
}

static AForm*	_makePresidentialPardonForm(std::string formTarget) {
	return (new PresidentialPardonForm(formTarget));
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget) const {
	AForm* (*creationMethods[])(std::string) =
		{_makeShrubberyCreationForm, _makeRobotomyRequestForm, _makePresidentialPardonForm};
	std::string	formNames[] =
		{"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (unsigned long i = 0; i < sizeof(formNames); i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (creationMethods[i](formTarget));
		}
	}
	std::cout << "Error: Form " << formName << " does not exist" << std::endl;
	return (NULL);
}
