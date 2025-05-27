#pragma once

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

	void	beExecuted(const Bureaucrat& executor) const;

private:
	RobotomyRequestForm();
	std::string	_target;
};
