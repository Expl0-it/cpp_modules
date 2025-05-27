#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &src);
	~PresidentialPardonForm();

	void	beExecuted(const Bureaucrat& executor) const;

private:
	PresidentialPardonForm();
	std::string	_target;
};
