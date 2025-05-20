#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string name, int grade)
: _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat " << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
: _name(src._name), _grade(src._grade) {
	std::cout << "Bureaucrat " << src._name << " copied" << std::endl;
}

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src) {
		this->_grade = src._grade;
	}
	std::cout << "Bureaucrat " << src._name << " assigned" << std::endl;
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat) {
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (stream);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

std::string		Bureaucrat::getName() const {
	return (_name);
}

int				Bureaucrat::getGrade() const {
	return (_grade);
}

void			Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void			Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char*		Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high exception");
}

const char*		Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low exception");
}
