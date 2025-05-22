#pragma once

#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat &operator=(const Bureaucrat& src);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	void		signForm(Form& form);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	Bureaucrat();
	std::string const	_name;
	int					_grade;
};
std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);
