/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:48:06 by julien            #+#    #+#             */
/*   Updated: 2025/06/07 12:14:13 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) :
	_accountIndex(_nbAccounts),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	t::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "created";
	std::cout << std::endl;
	t::_nbAccounts++;
	return ;
}

Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	t::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "created";
	std::cout << std::endl;
	t::_nbAccounts++;
	t::_totalAmount += initial_deposit;
	return ;
}

Account::~Account(void)
{
	t::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "closed";
	std::cout << std::endl;
	t::_nbAccounts--;
	return ;
}

int		Account::getNbAccounts(void)
{
	return (t::_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (t::_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (t::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (t::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	t::_displayTimestamp();
	std::cout << " ";
	std::cout << "accounts:" << t::getNbAccounts() << ";";
	std::cout << "total:" << t::getTotalAmount() << ";";
	std::cout << "deposits:" << t::getNbDeposits() << ";";
	std::cout << "withdrawals:" << t::getNbWithdrawals();
	std::cout << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	t::_totalNbDeposits++;
	t::_totalAmount += deposit;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = this->_amount;
	this->_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (t::checkAmount() >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->checkAmount() << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
		std::cout << std::endl;
		t::_totalAmount -= withdrawal;
		t::_totalNbWithdrawals++;
		return (true);
	}
	std::cout << "withdrawal:" << "refused";
	std::cout << std::endl;
	return (false);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	t::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	struct tm	newtime;
	time_t		ltime;
	char		buf[16];

	//std::cout << "[19920104_091532]";
	ltime = time(0);
	localtime_r(&ltime, &newtime);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &newtime);
	std::cout << "[" << buf << "]";
	return ;
}
