#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void) {
	Bureaucrat low("Jake", 150);
	Bureaucrat high("Bubblegum", 1);
	Bureaucrat mid("Finn", 75);

	Form easy("easy", 150, 150);
	Form medium("medium", 100, 75);
	Form hard("hard", 50, 1);
	try {
		Form rand("random", 150, 0);
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

	return 0;
}
