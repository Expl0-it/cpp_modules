#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
public:
	Span(unsigned int maxNumCount);
	Span(const Span &src);
	Span &operator=(const Span &src);
	~Span();

	void			addNumber(int num);
	void			addNumbers(std::vector<int>::iterator from, std::vector<int>::iterator to);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	class SpanVecFullException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};

	class SpanVecTooSmallException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};

private:
	unsigned int	_maxNumsCount;
	std::vector<int>	_numbers;
	Span();
};
