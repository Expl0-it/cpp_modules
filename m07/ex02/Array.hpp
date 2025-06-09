#pragma once

#include <iostream>
#include <cstring>

template<typename T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	Array &operator=(const Array &src);
	~Array();

	T& operator[](unsigned int i);
	T& operator[](unsigned int i) const;

	unsigned int	size() const;

	class OutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Index out of bounds exception");
		}
	};

private:
	T*				elements;
	unsigned int	elements_count;
};

#include "Array.inc.hpp"
