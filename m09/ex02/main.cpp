#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>

int main(int argc, char *argv[])
{
	if (1 == argc)
	{
		std::cout << "Wrong arg count" << std::endl;
		return (1);
	}

	std::list<int> listNums;
	std::deque<int> dequeNums;
	int num;
	for (int i = 0; NULL != argv[i]; i++)
	{
		num = std::atoi(argv[i]);
		if (num < 0)
		{
			std::cout << "Invalid input: negative number" << std::endl;
			return (1);
		}
		listNums.push_back(num);
		dequeNums.push_back(num);
	}

	ListSorter list_sorter(listNums);
	std::clock_t time = list_sorter.start();
	std::cout << "Time to process a range of " << listNums.size() << " elements with std::list: " << time << "ms"
	          << std::endl;

	DequeSorter deque_sorter(dequeNums);
	time = deque_sorter.start();
	std::cout << "Time to process a range of " << listNums.size() << " elements with std::deque: " << time << "ms"
	          << std::endl;

	return 0;
}
