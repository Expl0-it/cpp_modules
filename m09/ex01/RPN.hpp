#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <exception>

class RPN {
public:
	RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);
	~RPN();

	bool			compute(std::string line);

	class DivideByZeroException : public std::exception {
	public:
		const char* what() const throw();
	};

private:
	std::stack<int>	_operands;
	int				_calculate(int a, int b, char sign);
};
