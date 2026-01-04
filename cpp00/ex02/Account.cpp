#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(NULL);
    std::tm *tm_ptr = std::localtime(&t);

    std::cout << "[";
    std::cout << (tm_ptr->tm_year + 1900);
    std::cout << std::setw(2) << std::setfill('0') << (tm_ptr->tm_mon + 1);
    std::cout << std::setw(2) << std::setfill('0') << tm_ptr->tm_mday;
    std::cout << "_";
    std::cout << std::setw(2) << std::setfill('0') << tm_ptr->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << tm_ptr->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << tm_ptr->tm_sec;
    std::cout << "] ";
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts ;
    std::cout << ";total:" << _totalAmount ;
    std::cout << ";deposits:" << _totalNbDeposits ;
    std::cout << ";withdrawals:" << _totalNbWithdrawals ;
    std::cout << std::endl;
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";amount:" << this->_amount ;
    std::cout << ";created" ;
    std::cout << std::endl;
}

Account::Account(void)
{
    this->_accountIndex = 0;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";amount:" << this->_amount ;
    std::cout << ";closed" ;
    std::cout << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";p_amount:" << this->_amount ;
    std::cout << ";deposit:" << deposit ;

    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << ";amount:" << this->_amount ;
    std::cout << ";nb_deposits:" << this->_nbDeposits ;
    std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";p_amount:" << this->_amount ;
    std::cout << ";withdrawal:" ;

    if (withdrawal > this->_amount)
    {
        std::cout << "refused" ;
        std::cout << std::endl;
        return (false);
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << withdrawal ;
    std::cout << ";amount:" << this->_amount ;
    std::cout << ";nb_withdrawals:" << this->_nbWithdrawals ;
    std::cout << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";amount:" << this->_amount ;
    std::cout << ";deposits:" << this->_nbDeposits ;
    std::cout << ";withdrawals:" << this->_nbWithdrawals ;
    std::cout << std::endl;
}
