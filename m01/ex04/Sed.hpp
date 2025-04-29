#pragma once
#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class	Sed{
private:
	Sed();

	std::string		_filename;
	std::string		_s1;
	std::string		_s2;
	std::ifstream	_ifs;
	std::ofstream	_ofs;

	std::string	_changeLine();
	bool		_writeLine();

public:
	Sed(std::string filename, std::string s1, std::string s2);
	~Sed();

	// NOTE: always call after constructor
	bool	filesOpened();
	bool	writeFile();
};

#endif // !SED_HPP
