/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:18:15 by julien            #+#    #+#             */
/*   Updated: 2025/06/10 10:15:16 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

const	std::string Harl::_levels[4] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

void (Harl::* const Harl::_dispatch_table[4])(void) const = {
	&Harl::_debug,
	&Harl::_info,
	&Harl::_warning,
	&Harl::_error
};

Harl::Harl(void)
{
	std::cout << "Harl : Default Constructor called" << std::endl;
	return ;
}

Harl::Harl(Harl const &src)
{
	std::cout << "Harl : Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Harl::~Harl(void)
{
	std::cout << "Harl : Destructor called" << std::endl;
	return ;
}

Harl &Harl::operator=(Harl const &rhs)
{
	if (this != &rhs)
	{
		
	}
	return *this;
}

const std::string	Harl::getLevel(int index)
{
	if (index >= 0 && index < 4)
	{
		return (_levels[index]);
	}
	return ("");
}

void Harl::complain(std::string level) const
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (level == getLevel(i))
		{
			break ;
		}
		i++;
	}
	switch (i) {
		case 0:
			(this->*_dispatch_table[0])();
		case 1:
			(this->*_dispatch_table[1])();
		case 2:
			(this->*_dispatch_table[2])();
		case 3:
			(this->*_dispatch_table[3])();
			break ;
		case 4:
			std::cout << "Error : invalid level" << std::endl;
			break ;
	}
}

void	Harl::_debug(void) const
{
	std::cout << "[DEBUG]\nI love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!" << std::endl;
	return ;
}

void	Harl::_info(void) const
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
	return ;
}

void	Harl::_warning(void) const
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years, ";
	std::cout << "whereas you started working here just last month." << std::endl;
	return ;
}

void	Harl::_error(void) const
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &o, Harl const &harl)
{
	o << "This is a Harl object at adress " << &harl << std::endl;
	return o;
}
