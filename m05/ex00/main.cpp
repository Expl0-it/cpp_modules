#include "Bureaucrat.hpp"

int main (void) {
		Bureaucrat b1("Finn", 150);
		Bureaucrat b2("Jake", 1);
	try {
		Bureaucrat b3("Wrong1", 0);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat b4("Wrong2", 151);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	try {
		b1.decrementGrade();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		b1.incrementGrade();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;
	try {
		b2.incrementGrade();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		b2.decrementGrade();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << b2 << std::endl;

	return 0;
}
