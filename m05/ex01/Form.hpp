#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Form {
public:
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form& src);
	Form& operator=(const Form& src);
	~Form();

	const std::string	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	void				beSigned(Bureaucrat& b);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class AlreadySignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	Form();
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
};
std::ostream&	operator<<(std::ostream& stream, const Form& form);
