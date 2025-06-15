#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& src) {
	*this = src;
}

RPN& RPN::operator=(const RPN& src) {
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

RPN::~RPN() {}

int RPN::_calculate(int a, int b, char sign) {
	if (0 == b && '/' == sign)
		throw DivideByZeroException();
	switch (sign) {
		case '+': return (a + b);
		case '-': return (a - b);
		case '*': return (a * b);
		default: return  (a / b);
	}
}

bool RPN::compute(std::string line) {
	int		a, b, res;

	for (std::string::iterator i = line.begin(); i != line.end(); i++) {
		if (std::isspace(*i))
			continue;
		if (std::isdigit(*i))
			_operands.push(*i - '0');
		else if ('+' == *i || '-' == *i || '*' == *i || '/' == *i) {
			if (_operands.size() < 2)
				return (std::cerr << "Invalid number of operands before operator" << std::endl,
				false);
			b = _operands.top();
			_operands.pop();
			a = _operands.top();
			_operands.pop();
			res = _calculate(a, b, *i);
			_operands.push(res);
		}
		else
			return (std::cerr << "Invalid operator" << std::endl,
			false);
	}
	if (1 != _operands.size())
		return (std::cerr << "Invalid number of opeartors regarding the operants" << std::endl,
		false);
	std::cout << "The total is: " << _operands.top() << std::endl;
	return (true);
}

const char* RPN::DivideByZeroException::what() const throw() {
	return ("Error: Division by zero exception");
}
