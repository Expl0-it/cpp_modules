#pragma once

#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm {
public:

#define TREE "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n"

	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();

	void	beExecuted(const Bureaucrat& executor) const;

private:
	ShrubberyCreationForm();
	std::string	_target;
};
