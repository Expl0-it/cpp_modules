#pragma once

#include <iostream>
#include <cstdlib>
#include <iomanip>

class ScalarConverter {
public:
	static void		convert(const std::string literal);

	typedef struct 	vals {
		char	char_val;
		int		int_val;
		float	float_val;
		double	double_val;
		bool	isOk;
	}				t_vals;

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();
};
