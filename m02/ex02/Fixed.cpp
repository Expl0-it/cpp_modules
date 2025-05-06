#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed&	Fixed::operator=(const Fixed &assign) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &assign)
		this->setRawBits(assign.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fix) {
	stream << fix.toFloat();
	return (stream);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->_value / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const {
	return ((int)this->_value >> _fractionalBits);
}

bool	operator > (const Fixed &fst, const Fixed &snd){
	return (fst.getRawBits() > snd.getRawBits());
}

bool	operator < (const Fixed &fst, const Fixed &snd){
	return (fst.getRawBits() < snd.getRawBits());
}

bool	operator >= (const Fixed &fst, const Fixed &snd){
	return (fst.getRawBits() >= snd.getRawBits());
}

bool	operator <= (const Fixed &fst, const Fixed &snd){
	return (fst.getRawBits() <= snd.getRawBits());
}

bool	operator == (const Fixed &fst, const Fixed &snd){
	return (fst.getRawBits() == snd.getRawBits());
}

bool	operator != (const Fixed &fst, const Fixed &snd){
	return (fst.getRawBits() != snd.getRawBits());
}


Fixed	operator + (const Fixed &fst, const Fixed &snd){
	return (fst.toFloat() + snd.toFloat());
}

Fixed	operator - (const Fixed &fst, const Fixed &snd){
	return (fst.toFloat() - snd.toFloat());
}

Fixed	operator * (const Fixed &fst, const Fixed &snd){
	return (fst.toFloat() * snd.toFloat());
}

Fixed	operator / (const Fixed &fst, const Fixed &snd){
	if (snd.toFloat() == 0) {
		std::cout << "Division by 0 error, returning 0" << std::endl;
		return (0);
	}
	return (fst.toFloat() / snd.toFloat());
}

Fixed&	Fixed::operator ++ (){
	++(this->_value);
	return (*this);
}

Fixed	Fixed::operator ++ (int){
	Fixed ret = *this;
	++(this->_value);
	return (ret);
}

Fixed&	Fixed::operator -- (){
	--(this->_value);
	return (*this);
}

Fixed	Fixed::operator -- (int){
	Fixed ret = *this;
	--(this->_value);
	return (ret);
}

Fixed&		Fixed::min(Fixed &fst, Fixed &snd){
	if (fst <= snd) {
		return (fst);
	}
	return (snd);
}

const Fixed&	Fixed::min(Fixed const &fst, Fixed const &snd){
	if (fst.toFloat() <= snd.toFloat()) {
		return (fst);
	}
	return (snd);
}

Fixed&		Fixed::max(Fixed &fst, Fixed &snd){
	if (fst >= snd) {
		return (fst);
	}
	return (snd);
}

const Fixed&	Fixed::max(Fixed const &fst, Fixed const &snd){
	if (fst.toFloat() >= snd.toFloat()) {
		return (fst);
	}
	return (snd);
}
