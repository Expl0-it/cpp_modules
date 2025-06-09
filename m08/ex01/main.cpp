#include "Span.hpp"

#include <cstdlib>
#include <ctime>

int main(void) {

	srand(time(NULL));

	std::cout << "	Subject test:" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl << "	100 test:" << std::endl;
	{
		Span span(100);
		std::vector<int> tmp;
		for (int i = 0; i < 100; i++)
			tmp.push_back(rand() % 1000000);
		span.addNumbers(tmp.begin(), tmp.end());
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}

	std::cout << std::endl << "	100,000 test:" << std::endl;
	{
		Span span(100000);
		std::vector<int> tmp;
		for (int i = 0; i < 10000; i++)
			tmp.push_back(rand() % 100000000);
		span.addNumbers(tmp.begin(), tmp.end());
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	return (0);
}
