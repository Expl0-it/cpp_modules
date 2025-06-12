#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();

	bool	readDBfile(const char* dbFileName);
	bool	processInputFile(const char* inputFileName);

private:
	std::map<std::string, float>	_rates;
	float							_getRate(std::string date);
};
