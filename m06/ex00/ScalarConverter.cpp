#include "ScalarConverter.hpp"

static std::string	checkFloatSpecialCase(const std::string literal) {
	int len = literal.length();

	if (4 == len) {
		if (0 == literal.compare("nanf"))
			return ("nanf");
	}
	else if (5 == len) {
		if (0 == literal.compare("-inff"))
			return ("-inff");
		if (0 == literal.compare("+inff"))
			return ("+inff");
	}
	return ("");
}

static std::string	checkDoubleSpecialCase(const std::string literal) {
	int len = literal.length();

	if (3 == len) {
		if (0 == literal.compare("nan"))
			return ("nan");
	}
	else if (4 == len) {
		if (0 == literal.compare("-inf"))
			return ("-inf");
		if (0 == literal.compare("+inf"))
			return ("+inf");
	}
	return ("");
}

static void			printSpecial(std::string special) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (std::string::npos != special.find("nan")) {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (std::string::npos != special.find("-inf")) {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (std::string::npos != special.find("+inf")) {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
		std::cout << "FATAL ERROR" << std::endl;
}

static bool			handleSpecial(std::string literal) {
	std::string special = "";

	special = checkFloatSpecialCase(literal);
	if ("" != special) {
		printSpecial(special);
		return true;
	}
	special = checkDoubleSpecialCase(literal);
	if ("" != special) {
		printSpecial(special);
		return true;
	}
	return (false);
}

static void			handleFloatingPoing(std::string literal, ScalarConverter::t_vals* vals) {
	if (std::string::npos != literal.find("f")) {
		vals->float_val = static_cast<float>(std::atof(literal.c_str()));
		vals->double_val = static_cast<double>(vals->float_val);
		vals->int_val = static_cast<int>(vals->float_val);
	}
	else {
		vals->double_val = static_cast<double>(std::atof(literal.c_str()));
		vals->float_val = static_cast<float>(vals->double_val);
		vals->int_val = static_cast<int>(vals->double_val);
	}
}

static void			handleInt(std::string literal, ScalarConverter::t_vals* vals) {
	vals->int_val = static_cast<int>(std::atoi(literal.c_str()));
	vals->float_val = static_cast<float>(vals->int_val);
	vals->double_val = static_cast<double>(vals->int_val);
}

static bool			checkIsNum(std::string literal) {
	int	i = 0;

	while (true == std::isspace(literal[i]))
		i++;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if ('.' == literal[i])
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if ('f' == literal[i])
		i++;
	while (true == std::isspace(literal[i]))
		i++;
	if (0 == literal[i])
		return (true);
	else
		return (false);
}

void		ScalarConverter::convert(const std::string literal) {
	ScalarConverter::t_vals vals;

	if (true == handleSpecial(literal))
		return ;
	(void)vals;
}

