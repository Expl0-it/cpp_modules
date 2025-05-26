#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5),
_target(target)
{
	std::cout << "This Form is a PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
: AForm(src),
_target(src._target)
{
	std::cout << "This Form is a PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm&			PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	std::cout << "PresidentialPardonForm assigment constructor called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

void	PresidentialPardonForm::beExecuted(const Bureaucrat& executor) const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox - executed by " << executor.getName() << std::endl;
}
