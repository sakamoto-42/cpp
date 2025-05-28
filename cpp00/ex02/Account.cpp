/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:48:06 by julien            #+#    #+#             */
/*   Updated: 2025/05/28 11:52:15 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) :
	_accountIndex(_nbAccounts + 1),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	t::_nbAccounts++;
	return ;
}

Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts + 1),
	_amount(initial_deposit),
	_nbDeposits(1),
	_nbWithdrawals(0)
{
	t::_nbAccounts++;
	t::_totalAmount += initial_deposit;
	t::_totalNbDeposits++;
	return ;
}

Account::~Account(void)
{
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
	std::cout << "Account Infos" << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	this->_amount += deposit;
	t::_totalNbDeposits++;
	t::_totalAmount += deposit;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		return (true);
	}
	return (false);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	std::cout << "Display Status" << std::endl;
	return ;
}

void	_displayTimestamp(void)
{
	//?

}
