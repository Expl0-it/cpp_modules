#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main (void) {
	Bureaucrat low("Jake", 150);
	Bureaucrat high("Bubblegum", 1);
	Bureaucrat mid("Finn", 75);

	ShrubberyCreationForm easy("file");
	ShrubberyCreationForm medium("file");
	ShrubberyCreationForm hard("file");
	try {
		ShrubberyCreationForm rand("file");
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	low.signForm(easy);
	low.signForm(hard);
	mid.signForm(easy);
	mid.signForm(medium);
	mid.signForm(hard);
	high.signForm(easy);
	high.signForm(hard);
	low.executeForm(easy);
	high.executeForm(hard);

	return 0;
}
