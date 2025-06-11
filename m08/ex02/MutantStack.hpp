#pragma once

#include <stack>
#include <iostream>
#include <deque>

template<typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C >{
public:
	MutantStack();
	MutantStack(const MutantStack &src);
	MutantStack &operator=(const MutantStack &src);
	~MutantStack();

	typedef typename C::iterator iterator;

	iterator begin();
	iterator end();

private:

};

#include "MutantStack.inc.hpp"
