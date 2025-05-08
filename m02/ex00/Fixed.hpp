#pragma once

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed &assign);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_value;
	static const int	_fractionalBits = 8;
};
