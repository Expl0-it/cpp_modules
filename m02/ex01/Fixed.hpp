#pragma once

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &assign);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_value;
	static const int	_fractionalBits = 8;
};
std::ostream& operator<<(std::ostream &stream, const Fixed &fix);
