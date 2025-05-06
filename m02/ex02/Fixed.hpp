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

	// NOTE: Parameter overloading for non-canonical operators
	friend std::ostream&	operator << (std::ostream &stream, const Fixed &fix);

	friend bool				operator > (const Fixed &fst, const Fixed &snd);
	friend bool				operator < (const Fixed &fst, const Fixed &snd);
	friend bool				operator >= (const Fixed &fst, const Fixed &snd);
	friend bool				operator <= (const Fixed &fst, const Fixed &snd);
	friend bool				operator == (const Fixed &fst, const Fixed &snd);
	friend bool				operator != (const Fixed &fst, const Fixed &snd);

	friend Fixed			operator + (const Fixed &fst, const Fixed &snd);
	friend Fixed			operator - (const Fixed &fst, const Fixed &snd);
	friend Fixed			operator * (const Fixed &fst, const Fixed &snd);
	friend Fixed			operator / (const Fixed &fst, const Fixed &snd);

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
