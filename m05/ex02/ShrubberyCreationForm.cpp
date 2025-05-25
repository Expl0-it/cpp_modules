#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137),
_target(target)
{
	std::cout << "This Form is a ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: AForm(src),
_target(src._target)
{
	std::cout << "This Form is a ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm&			ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	std::cout << "ShrubberyCreationForm assigment constructor called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

void	ShrubberyCreationForm::beExecuted(const Bureaucrat& executor) const {
	std::ofstream out;

	out.open((this->_target + "_shrubbery").c_str());
	if (true == out.fail()) {
		std::cerr << "Could not open file" << std::endl;
		return ;
	}
	out << TREE;
	out.close();
	std::cout << executor.getName() << " created a shrubbery" << std::endl;
}
