#include "ArgCheck.hpp"
#include "BitcoinExchange.hpp"

int main (int argc, char *argv[]) {
	if (false == ArgCheck::checkArgCount(argc, 2))
		return (1);

	BitcoinExchange handler;

	if (false == handler.readDBfile("data.csv"))
		return (2);

	if (false == handler.processInputFile(argv[1]))
		return (3);

	return 0;
}
