#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void) {
	Bureaucrat low("Jake", 150);
	Bureaucrat high("Bubblegum", 1);
	Bureaucrat mid("Finn", 42);

	ShrubberyCreationForm easy("file");
	RobotomyRequestForm medium("human");
	PresidentialPardonForm hard("citizen");

	AForm* heap = new PresidentialPardonForm("file2");
	high.signForm(*heap);
	delete heap;

	try {
		ShrubberyCreationForm valid("file");
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	high.executeForm(easy);
	low.signForm(easy);
	low.signForm(medium);
	low.signForm(hard);
	mid.signForm(easy);
	mid.signForm(medium);
	mid.signForm(hard);
	high.signForm(medium);
	high.signForm(hard);
	high.signForm(hard);
	low.executeForm(easy);
	low.executeForm(medium);
	low.executeForm(hard);
	mid.executeForm(easy);
	mid.executeForm(medium);
	mid.executeForm(hard);
	high.executeForm(medium);
	high.executeForm(hard);

	return 0;
}
