#include "PmergeMe.hpp"

ListSorter::ListSorter(std::list<int> numbers) : count(numbers.size()), groupSize(1), numbers(numbers)
{
}

ListSorter::ListSorter(const ListSorter &src)
{
	groupSize = src.groupSize;
	count = src.count;
	numbers = src.numbers;
	*this = src;
}

ListSorter &ListSorter::operator=(const ListSorter &src)
{
	if (this != &src)
	{
		numbers.clear();
		groupSize = src.groupSize;
		count = src.count;
		numbers = src.numbers;
		*this = src;
	}
	return *this;
}

ListSorter::~ListSorter()
{
}

int ListSorter::JSNumber(int level)
{
	int pow = std::pow(2, level);
	int pow2 = std::pow(-1, level);
	return (pow - pow2) / 3;
}

void ListSorter::swapPairs(std::list<t_listpair> &pairs)
{
	for (std::list<t_listpair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		std::list<t_listpair>::iterator it2 = it;
		it2++;
		if (it2 == pairs.end())
			continue;
		if (it->numbers.back() > it2->numbers.back() && it2->numbers.size() == groupSize)
			it->numbers.swap(it2->numbers);
		it++;
	}
}

void ListSorter::addLabels(std::list<t_listpair> &pairs)
{
	bool isOdd = false;
	for (std::list<t_listpair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->numbers.size() != groupSize)
			return;
		it->side = isOdd ? 'a' : 'b';
		isOdd = !isOdd;
	}
}

void ListSorter::fillPairs(std::list<t_listpair> &pairs)
{
	for (size_t i = 0; i < count; i += groupSize)
	{
		t_listpair pairList;
		for (size_t j = 0; j < groupSize; j++)
		{
			if (i + j >= count)
				continue;
			pairList.numbers.push_back(numbers.front());
			numbers.pop_front();
		}
		if (pairList.numbers.size() == groupSize)
		{
			pairList.side = 'a';
			pairList.pairNumber = (i / (groupSize * 2)) + 1;
		}
		else
		{
			pairList.side = 'x';
			pairList.pairNumber = 0;
		}
		pairs.push_back(pairList);
	}
}

void ListSorter::fillNums(std::list<t_listpair> &pairs)
{
	numbers.clear();
	for (std::list<t_listpair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		for (std::list<int>::iterator it2 = it->numbers.begin(); it2 != it->numbers.end(); it2++)
			numbers.push_back(*it2);
	}
}

std::list<t_listpair>::iterator ListSorter::mainPos(std::list<t_listpair> &main, int num)
{
	for (std::list<t_listpair>::iterator it = main.begin(); it != main.end(); it++)
	{
		if (it->numbers.back() > num)
			return it;
	}
	return main.end();
}

void ListSorter::mergeNums()
{
	std::list<t_listpair> pending;
	std::list<t_listpair> main;
	std::list<t_listpair> pairs;
	std::list<t_listpair> left;

	fillPairs(pairs);
	addLabels(pairs);

	for (std::list<t_listpair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (1 == it->pairNumber || 'a' == it->side)
			main.push_back(*it);
		else if ('b' == it->side)
			pending.push_back(*it);
		else
			left.push_back(*it);
	}
	int startNum = 3;
	while (main.size() + left.size() < pairs.size())
	{
		int previousNum = JSNumber(startNum - 1);
		int jsNum = JSNumber(startNum);
		for (int i = jsNum; i > previousNum; i--)
		{
			for (std::list<t_listpair>::iterator it = pending.begin(); it != pending.end(); it++)
				if (i == it->pairNumber)
					main.insert(mainPos(main, it->numbers.back()), *it);
		}
		startNum++;
	}
	if (!left.empty())
		main.push_back(left.back());
	fillNums(main);

	groupSize /= 2;
	if (groupSize > 0)
		mergeNums();
}

void ListSorter::sortNums()
{
	std::list<t_listpair> pairs;
	fillPairs(pairs);
	swapPairs(pairs);
	fillNums(pairs);

	groupSize *= 2;
	if (groupSize <= count / 2)
		sortNums();
}

clock_t ListSorter::start()
{
	if (0 == groupSize)
		return 0;

	std::clock_t c_start = std::clock();
	sortNums();
	groupSize /= 2;
	mergeNums();

	std::clock_t c_end = std::clock();

	std::cout << "After:  ";
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return c_end - c_start;
}

DequeSorter::DequeSorter(std::deque<int> numbers) : count(numbers.size()), groupSize(1), numbers(numbers)
{
}

DequeSorter::DequeSorter(const DequeSorter &src)
{
	groupSize = src.groupSize;
	count = src.count;
	numbers = src.numbers;
	*this = src;
}

DequeSorter &DequeSorter::operator=(const DequeSorter &src)
{
	if (this != &src)
	{
		numbers.clear();
		groupSize = src.groupSize;
		count = src.count;
		numbers = src.numbers;
		*this = src;
	}
	return *this;
}

DequeSorter::~DequeSorter()
{
}

int DequeSorter::JSNumber(int level)
{
	int pow = std::pow(2, level);
	int pow2 = std::pow(-1, level);
	return (pow - pow2) / 3;
}

void DequeSorter::swapPairs(std::deque<t_dequepair> &pairs)
{
	for (std::deque<t_dequepair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		std::deque<t_dequepair>::iterator it2 = it;
		it2++;
		if (it2 == pairs.end())
			continue;
		if (it->numbers.back() > it2->numbers.back() && it2->numbers.size() == groupSize)
			it->numbers.swap(it2->numbers);
		it++;
	}
}

void DequeSorter::addLabels(std::deque<t_dequepair> &pairs)
{
	bool isOdd = false;
	for (std::deque<t_dequepair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->numbers.size() != groupSize)
			return;
		it->side = isOdd ? 'a' : 'b';
		isOdd = !isOdd;
	}
}

void DequeSorter::fillPairs(std::deque<t_dequepair> &pairs)
{
	for (size_t i = 0; i < count; i += groupSize)
	{
		t_dequepair pairList;
		for (size_t j = 0; j < groupSize; j++)
		{
			if (i + j >= count)
				continue;
			pairList.numbers.push_back(numbers.front());
			numbers.pop_front();
		}
		if (pairList.numbers.size() == groupSize)
		{
			pairList.side = 'a';
			pairList.pairNumber = (i / (groupSize * 2)) + 1;
		}
		else
		{
			pairList.side = 'x';
			pairList.pairNumber = 0;
		}
		pairs.push_back(pairList);
	}
}

void DequeSorter::fillNums(std::deque<t_dequepair> &pairs)
{
	numbers.clear();
	for (std::deque<t_dequepair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		for (std::deque<int>::iterator it2 = it->numbers.begin(); it2 != it->numbers.end(); it2++)
			numbers.push_back(*it2);
	}
}

std::deque<t_dequepair>::iterator DequeSorter::mainPos(std::deque<t_dequepair> &main, int num)
{
	for (std::deque<t_dequepair>::iterator it = main.begin(); it != main.end(); it++)
	{
		if (it->numbers.back() > num)
			return it;
	}
	return main.end();
}

void DequeSorter::mergeNums()
{
	std::deque<t_dequepair> pending;
	std::deque<t_dequepair> main;
	std::deque<t_dequepair> pairs;
	std::deque<t_dequepair> left;

	fillPairs(pairs);
	addLabels(pairs);

	for (std::deque<t_dequepair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (1 == it->pairNumber || 'a' == it->side)
			main.push_back(*it);
		else if ('b' == it->side)
			pending.push_back(*it);
		else
			left.push_back(*it);
	}
	int startNum = 3;
	while (main.size() + left.size() < pairs.size())
	{
		int previousNum = JSNumber(startNum - 1);
		int jsNum = JSNumber(startNum);
		for (int i = jsNum; i > previousNum; i--)
		{
			for (std::deque<t_dequepair>::iterator it = pending.begin(); it != pending.end(); it++)
				if (i == it->pairNumber)
					main.insert(mainPos(main, it->numbers.back()), *it);
		}
		startNum++;
	}
	if (!left.empty())
		main.push_back(left.back());
	fillNums(main);

	groupSize /= 2;
	if (groupSize > 0)
		mergeNums();
}

void DequeSorter::sortNums()
{
	std::deque<t_dequepair> pairs;
	fillPairs(pairs);
	swapPairs(pairs);
	fillNums(pairs);

	groupSize *= 2;
	if (groupSize <= count / 2)
		sortNums();
}

clock_t DequeSorter::start()
{
	if (0 == groupSize)
		return 0;

	std::clock_t c_start = std::clock();
	sortNums();
	groupSize /= 2;
	mergeNums();

	std::clock_t c_end = std::clock();

	return c_end - c_start;
}
