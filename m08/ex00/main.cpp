#include "easyfind.hpp"
#include <list>
#include <vector>

int	main(void) {
	{
		std::list<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		list.push_back(5);

		std::list<int>::iterator val;
		val = easyfind< std::list<int> >(list, 5);
		if (val == list.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << *val << std::endl;
	}
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		std::vector<int>::iterator val;
		val = easyfind(vec, 7);
		if (val == vec.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << *val << std::endl;
	}
}
