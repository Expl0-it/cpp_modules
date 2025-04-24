#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


int	Account::getNbAccounts( void ){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout <<
		"accounts:" << getNbAccounts() <<
		";total:" << getTotalAmount() <<
		";deposits:" << getNbDeposits() <<
		";withdrawals:" << getNbWithdrawals() <<
		std::endl;
}

Account::Account( int initial_deposit ){
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	_nbAccounts++;
	this->_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";amount:" << _amount <<
		";created" <<
		std::endl;
}

Account::~Account( void ){
	this->_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";amount:" << _amount <<
		";closed" <<
		std::endl;
}

void	Account::makeDeposit( int deposit ){
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	this->_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";p_amount:" << _amount - deposit <<
		";deposit:" << deposit <<
		";amount:" << _amount <<
		";nb_deposits:" << _nbDeposits <<
		std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	if (withdrawal > this->_amount){
		this->_displayTimestamp();
		std::cout <<
			"index:" << _accountIndex <<
			";p_amount:" << _amount <<
			";withdrawal:refused" <<
			std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;

	this->_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";p_amount:" << _amount + withdrawal <<
		";withdrawal:" << withdrawal <<
		";amount:" << _amount <<
		";nb_withdrawals:" << _nbWithdrawals <<
		std::endl;

	return (true);
}

int		Account::checkAmount( void ) const{
	return (this->_amount);
}

void	Account::displayStatus( void ) const{
	this->_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";amount:" << _amount <<
		";deposits:" << _nbDeposits <<
		";withdrawals:" << _nbWithdrawals <<
		std::endl;
}

void	Account::_displayTimestamp( void ){
	std::time_t res = std::time(NULL);
	struct tm timenow = *std::localtime(&res);

	std::cout << "[" << timenow.tm_year + 1900 << 
	std::setfill('0') << std::setw(2) << timenow.tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << timenow.tm_mday << "_" <<
	std::setfill('0') << std::setw(2) << timenow.tm_hour <<
	std::setfill('0') << std::setw(2) << timenow.tm_min <<
	std::setfill('0') << std::setw(2) << timenow.tm_sec << "] ";
}
