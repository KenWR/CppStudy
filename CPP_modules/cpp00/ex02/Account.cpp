#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout \
	<< "accounts:" << Account::getNbAccounts() << ';' \
	<< "total:" << Account::getTotalAmount() << ';' \
	<< "deposits:" << Account::getNbDeposits() << ';' \
	<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) {
	_displayTimestamp();

	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;

	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "closed" << std::endl;
}

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	std::cout << "deposit:" << deposit << ';';
	
	//calculation
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';

	//calculation
	if (withdrawal > this->_amount) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;

	std::cout << "withdrawal:" << withdrawal << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount( void ) const {
	return this->_amount;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout \
	<< "index:" << this->_accountIndex << ';' \
	<< "amount:" << this->_amount << ';' \
	<< "deposits:" << this->_nbDeposits << ';' \
	<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	char buf[20];

	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", now);
	std::cout << buf;	
}
