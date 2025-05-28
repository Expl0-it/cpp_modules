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

void		ScalarConverter::convert(const std::string literal) {
	ScalarConverter::t_vals vals;

	if (true == handleSpecial(literal))
		return ;
	(void)vals;
}

