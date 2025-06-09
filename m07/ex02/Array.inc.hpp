#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array() : elements(NULL), elements_count(0) {}

template<typename T>
Array<T>::Array(unsigned int n): elements(new T[n]), elements_count(n) {
	for (unsigned int i = 0; i < elements_count; i++) {
		elements[i] = static_cast<T>(0);
	}
}

template<>
Array<std::string>::Array(unsigned int n): elements(new std::string[n]), elements_count(n) {
	for (unsigned int i = 0; i < elements_count; i++) {
		elements[i] = "";
	}
}

template<typename T>
Array<T>::Array(const Array &src) : elements(new T[src.size()]), elements_count(src.size()) {
	for (unsigned int i = 0; i < elements_count; i++)
		elements[i] = src.elements[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &src) {
	if (this != &src) {
		delete[] elements;
		elements_count = src.size();
		elements = new T[elements_count];
		for (unsigned int i = 0; i < elements_count; i++)
			elements[i] = src.elements[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array() {
	delete[] elements;
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= elements_count)
		throw OutOfBoundsException();
	return (elements[i]);
}

template<typename T>
T& Array<T>::operator[](unsigned int i) const {
	if (i >= elements_count)
		throw OutOfBoundsException();
	return (elements[i]);
}

template<typename T>
unsigned int	Array<T>::size() const {
	return elements_count;
}
