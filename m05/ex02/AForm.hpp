#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class AForm {
public:
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm& src);
	AForm& operator=(const AForm& src);
	~AForm();

	const std::string	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	void				beSigned(Bureaucrat& b);
	void				execute(const Bureaucrat& executor) const;
	virtual void		beExecuted(const Bureaucrat& executor) const = 0;



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

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	AForm();
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
};
std::ostream&	operator<<(std::ostream& stream, const AForm& form);
