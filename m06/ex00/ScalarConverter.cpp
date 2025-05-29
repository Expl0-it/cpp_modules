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

static	bool checkIsChar(std::string literal, ScalarConverter::t_vals* vals) {
	int	i = 0;

	while (true == std::isspace(literal[i]))
		i++;
	if (std::isprint(literal[i]))
		i++;
	if (0 == literal[i]) {
		i --;
		vals->char_val = literal[i];
		vals->int_val = static_cast<int>(vals->char_val);
		vals->float_val = static_cast<float>(vals->char_val);
		vals->double_val = static_cast<double>(vals->double_val);
		return (true);
	}
	return (false);
}

static void			printValues(ScalarConverter::t_vals *vals) {
	if (false == vals->isOk) {
		std::cout << "Invalid value" << std::endl;
		return ;
	}
	if (isascii(vals->char_val)) {
		if (std::isprint(vals->char_val))
			std::cout << "char: " << vals->char_val << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: Non Ascii" << std::endl;
	std::cout << "int: " << vals->int_val << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << vals->float_val << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << vals->double_val << std::endl;
}

void		ScalarConverter::convert(const std::string literal) {
	ScalarConverter::t_vals vals;
	vals.isOk = true;

	if (true == handleSpecial(literal))
		return ;
	if (std::string::npos != literal.find("."))
		handleFloatingPoing(literal, &vals);
	else
		handleInt(literal, &vals);
	vals.char_val = static_cast<char>(vals.int_val);
	if (true == checkIsNum(literal))
		vals.isOk = true;
	else if (true == checkIsChar(literal, &vals))
		vals.isOk = true;
	else
		vals.isOk = false;
	printValues(&vals);
}

