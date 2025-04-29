#include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2)
: _filename(filename), _s1(s1), _s2(s2){
	this->_ifs.open(_filename.c_str());
	this->_ofs.open((_filename + ".replace").c_str());
	std::cout << "Created Sec object" << std::endl;
}

Sed::~Sed(){
	if (true == this->_ifs.is_open())
		this->_ifs.close();
	if (true == this->_ofs.is_open())
		this->_ofs.close();
	std::cout << "Closed files and destroyed Sed object" << std::endl;
}

// !!! IMPORTANT !!!
// NOTE: always call after constructor
bool	Sed::filesOpened(){
	if (true == this->_ifs.fail())
	{
		std::cout << "Opening input file failed" << std::endl;
		return (false);
	}
	if (true == this->_ofs.fail())
	{
		std::cout << "Opening output file failed" << std::endl;
		return (false);
	}
	return (true);
}

std::string	Sed::_changeLine(){
	std::string	line;
	if (false == filesOpened())
		return ("");
	if (std::getline(this->_ifs, line))
	{
		size_t pos = 0;
		while ((pos = line.find(this->_s1, pos)) != std::string::npos) {
			line.erase(pos, this->_s1.length());
			line.insert(pos, this->_s2);
			pos += this->_s2.length();
		}
		return (line);
	}
	return ("");
}

bool	Sed::_writeLine(){
	if (false == filesOpened())
		return (false);

	std::string	newline;
	newline = _changeLine();
	if ("" == newline)
		return (false);

	this->_ofs << newline << std::endl;
	return (true);
}

bool	Sed::writeFile(){
	if (false == filesOpened())
		return (false);
	while (_writeLine())
		;
	return (true);
}
