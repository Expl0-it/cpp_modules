#include "Span.hpp"

Span::Span(unsigned int maxNumCount)
: _maxNumsCount(maxNumCount)
{
}

Span::Span(const Span& src) {
	*this = src;
}

Span&	Span::operator=(const Span& src) {
	if (this != &src) {
		_maxNumsCount = src._maxNumsCount;
		_numbers = src._numbers;
	}
	return (*this);
}

Span::~Span() {
}

void	Span::addNumber(int num) {
	if (_maxNumsCount == _numbers.size())
		throw (SpanVecFullException());
	_numbers.push_back(num);
}

void	Span::addNumbers(std::vector<int>::iterator from, std::vector<int>::iterator to) {
	unsigned int dist = std::distance(from, to);
	if (_numbers.size() + dist > _maxNumsCount)
		throw (SpanVecFullException());
	_numbers.insert(_numbers.end(), from, to);
}

unsigned int	Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw (SpanVecTooSmallException());

	std::vector<int> sorted(_numbers.size());
	std::partial_sort_copy(_numbers.begin(), _numbers.end(), sorted.begin(), sorted.end());

	int	span = longestSpan();
	for(std::vector<int>::iterator i = sorted.begin(); i != sorted.end() - 1; i++) {
		if (*(i + 1) - *i < span)
			span = *(i + 1) - *i;
	}
	return (span);
}

unsigned int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw (SpanVecTooSmallException());

	std::vector<int>::iterator	min = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::iterator	max = std::max_element(_numbers.begin(), _numbers.end());
	return (*max - *min);
}

const char*	Span::SpanVecFullException::what() const throw() {
	return ("SpanVec is alredy full");
}

const char* Span::SpanVecTooSmallException::what() const throw() {
	return ("SpanVec has not enough elements");
}
