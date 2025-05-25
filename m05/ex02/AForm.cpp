#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int executeGrade)
: _name(name), _signed(false), _signGrade(signGrade), _execGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form " << _name << " created with signGrade " << _signGrade << " and execGrade " << executeGrade << std::endl;
}

AForm::AForm(const AForm& src)
: _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm&			AForm::operator=(const AForm& src)
{
	if (this != &src) {
		_signed = src._signed;
	}
	std::cout << "Form assigment constructor called" << std::endl;
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const AForm& form)
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

AForm::~AForm()
{
	std::cout << "Form " << _name << " desturctor called" << std::endl;
}

const std::string	AForm::getName() const
{
	return (_name);
}

bool				AForm::getSigned() const
{
	return (_signed);
}

int					AForm::getSignGrade() const
{
	return (_signGrade);
}

int					AForm::getExecuteGrade() const
{
	return (_execGrade);
}

void				AForm::beSigned(Bureaucrat& b)
{
	if (true == _signed)
		throw AForm::AlreadySignedException();
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void	AForm::execute(const Bureaucrat& executor) const {
	if (false == this->_signed)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->_execGrade)
		throw  (AForm::GradeTooLowException());
	else {
		std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
		this->beExecuted(executor);
	}
}

const char*			AForm::GradeTooHighException::what() const throw() {
	return ("Form: Grade too high exception");
}

const char*			AForm::GradeTooLowException::what() const throw() {
	return ("Form: Grade too low exception");
}

const char*			AForm::AlreadySignedException::what() const throw() {
	return ("Form: Already signed exception");
}

const char*			AForm::FormNotSignedException::what() const throw() {
	return ("Form: Form not signed exception");
}
