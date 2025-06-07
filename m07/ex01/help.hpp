#pragma once

#include <iostream>

template<typename T>
void	print(T& raw) {
	std::cout << raw << std::endl;
}

template<typename T>
void	increment(T& toIncr) {
	toIncr++;
}
