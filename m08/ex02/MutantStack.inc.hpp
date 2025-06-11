#pragma once

#include "MutantStack.hpp"

template<typename T, typename C>
MutantStack<T, C>::MutantStack() : std::stack<T, C>() {
}

template<typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack &src) {
	*this = src;
}

template<typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=(const MutantStack &src) {
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

template<typename T, typename C>
MutantStack<T, C>::~MutantStack() {
}

template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin() {
	return (this->c.begin());
}

template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end() {
	return (this->c.end());
}
