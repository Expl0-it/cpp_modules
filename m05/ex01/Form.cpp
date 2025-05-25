#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade)
: _name(name), _signed(false), _signGrade(signGrade), _execGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form " << _name << " created with signGrade " << _signGrade << " and execGrade " << executeGrade << std::endl;
}

Form::Form(const Form& src)
: _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form&			Form::operator=(const Form& src)
{
	if (this != &src) {
		_signed = src._signed;
	}
	std::cout << "Form assigment constructor called" << std::endl;
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Form& form)
{
	stream << 
		"Form " << form.getName() <<
		" has signGrade: " <<
		form.getSignGrade() <<
		"execGrade " <<
		form.getExecuteGrade() <<
		"and its signed status is: " <<
		form.getSigned() <<
		std::endl;
	return (stream);
}

Form::~Form()
{
	std::cout << "Form " << _name << " desturctor called" << std::endl;
}

const std::string	Form::getName() const
{
	return (_name);
}

bool				Form::getSigned() const
{
	return (_signed);
}

int					Form::getSignGrade() const
{
	return (_signGrade);
}

int					Form::getExecuteGrade() const
{
	return (_execGrade);
}

void				Form::beSigned(Bureaucrat& b)
{
	if (true == _signed)
		throw Form::AlreadySignedException();
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char*			Form::GradeTooHighException::what() const throw() {
	return ("Form: Grade too high exception");
}

const char*			Form::GradeTooLowException::what() const throw() {
	return ("Form: Grade too low exception");
}

const char*			Form::AlreadySignedException::what() const throw() {
	return ("Form: Already signed exception");
}
