#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this == &src) {
		*this = src;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
}

bool	BitcoinExchange::readDBfile(const char* dbFileName) {
	std::ifstream	dbFile;
	std::string		line;
	std::string		date;
	float			val;

	dbFile.open(dbFileName);
	if (dbFile.fail())
		return (std::cerr << "Cannot open DB file" << std::endl, false);
	while (std::getline(dbFile, line)) {
		if ("date,exchange_rate" == line)
			continue ;
		date = line.substr(0 , 10);
		val = std::atof(line.substr(11).c_str());
		_rates[date] = val;
	}
	dbFile.close();
	return (true);
}

float	BitcoinExchange::_getRate(std::string date) {
	std::map<std::string, float>::iterator i = _rates.find(date);
	if (_rates.end() != i) 
		return (i->second);

	struct tm timeGiven;
	struct tm timeChecked;
	strptime(date.c_str(), "%Y-%m-%d", &timeGiven);
	for
	(std::map<std::string, float>::reverse_iterator ri = _rates.rbegin();
	ri != _rates.rend();
	ri++) {
		strptime(ri->first.c_str(), "%Y-%m-%d", &timeChecked);
		if (timeGiven.tm_year < timeChecked.tm_year)
			continue ;
		if (timeGiven.tm_yday < timeChecked.tm_yday)
			continue ;
		return ri->second;
	}
	return (-1.0f);
}

bool	BitcoinExchange::processInputFile(const char* inputFileName) {
	std::ifstream	inputFile;
	std::string		line;
	std::string		date;
	float			val;
	struct tm		tm;
	float			rate;

	inputFile.open(inputFileName);
	if (inputFile.fail())
		return (std::cerr << "Cannot open input file" << std::endl, false);
	while (std::getline(inputFile, line)) {
		if ("date | value" == line)
			continue ;
		if (line.size() < 11) {
			std::cerr << "Error: invalid input => " << line << std::endl;
			continue ;
		}
		date = line.substr(0 ,10);
		val = std::atof(line.substr(12).c_str());
		if (val < 0) {
			std::cerr << "Error: negative number => " << val << std::endl;
			continue ;
		}
		if (val > 1000) {
			std::cerr << "Error: number too big => " << val << std::endl;
			continue ;
		}
		if (NULL == strptime(date.c_str(), "%Y-%m-%d", &tm)) {
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue ;
		}
		rate = _getRate(date);
		std::cout << date << " => " << val << " => " << (val * rate) << std::endl;
	}
	inputFile.close();
	return (true);
}
