#pragma once

#include <cmath>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

// NOTE: Deque
typedef struct s_dequepair
{
	char side;
	int pairNumber;
	std::deque<int> numbers;
} t_dequepair;

class DequeSorter
{
  private:
	DequeSorter();
	size_t count;
	size_t groupSize;
	std::deque<int> numbers;
	int JSNumber(int previous);
	void fillPairs(std::deque<t_dequepair> &pairs);
	void fillNums(std::deque<t_dequepair> &pairs);
	void swapPairs(std::deque<t_dequepair> &pairs);
	void addLabels(std::deque<t_dequepair> &pairs);
	std::deque<t_dequepair>::iterator mainPos(std::deque<t_dequepair> &pairs, int num);
	void mergeNums();
	void sortNums();

  public:
	DequeSorter(std::deque<int> numbers);
	DequeSorter(const DequeSorter &src);
	DequeSorter &operator=(const DequeSorter &src);
	~DequeSorter();
	std::clock_t start();
};

// NOTE: List
typedef struct s_listpair
{
	char side;
	int pairNumber;
	std::list<int> numbers;
} t_listpair;

class ListSorter
{
  private:
	ListSorter();
	size_t count;
	size_t groupSize;
	std::list<int> numbers;
	int JSNumber(int previous);
	void fillPairs(std::list<t_listpair> &pairs);
	void fillNums(std::list<t_listpair> &pairs);
	void swapPairs(std::list<t_listpair> &pairs);
	void addLabels(std::list<t_listpair> &pairs);
	std::list<t_listpair>::iterator mainPos(std::list<t_listpair> &pairs, int num);
	void mergeNums();
	void sortNums();

  public:
	ListSorter(std::list<int> numbers);
	ListSorter(const ListSorter &src);
	ListSorter &operator=(const ListSorter &src);
	~ListSorter();
	std::clock_t start();
};
