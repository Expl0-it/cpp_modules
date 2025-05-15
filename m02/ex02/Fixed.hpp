#pragma once

#include <iostream>
#include <cmath>

// TODO: Check all ex in this module
class Fixed {
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &assign);
	~Fixed();

	bool				operator > (const Fixed &other);
	bool				operator < (const Fixed &other);
	bool				operator >= (const Fixed &other);
	bool				operator <= (const Fixed &other);
	bool				operator == (const Fixed &other);
	bool				operator != (const Fixed &other);

	Fixed			operator + (const Fixed &other);
	Fixed			operator - (const Fixed &other);
	Fixed			operator * (const Fixed &other);
	Fixed			operator / (const Fixed &other);

	Fixed&					operator ++ ();
	Fixed					operator ++ (int);
	Fixed&					operator -- ();
	Fixed					operator -- (int);


	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	// NOTE: fn overloading
	static Fixed&		min(Fixed &fst, Fixed &snd);
	static const Fixed&	min(Fixed const &fst, Fixed const &snd);
	static Fixed&		max(Fixed &fst, Fixed &snd);
	static const Fixed&	max(Fixed const &fst, Fixed const &snd);

private:
	int					_value;
	static const int	_fractionalBits = 8;
};
std::ostream&	operator << (std::ostream &stream, const Fixed &fix);
