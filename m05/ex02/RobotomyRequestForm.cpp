#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45),
_target(target)
{
	std::cout << "This Form is a RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
: AForm(src),
_target(src._target)
{
	std::cout << "This Form is a RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm&			RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	std::cout << "RobotomyRequestForm assigment constructor called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

void	RobotomyRequestForm::beExecuted(const Bureaucrat& executor) const {
	int	random;
	
	srand(time(NULL));
	random = rand() % 2;
	std::cout << "Drilling noises" << std::endl;
	if (0 == random)
		std::cout << _target << "'s robotomy failed - executed by " << executor.getName() << std::endl;
	else
		std::cout << _target << " has been robotomized - executed by " << executor.getName() << std::endl;
}
