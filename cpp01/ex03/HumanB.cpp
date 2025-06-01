/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:36:39 by julien            #+#    #+#             */
/*   Updated: 2025/06/01 16:54:16 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB(void) : _name("default")
{
	std::cout << "HumanB " << "[" << this->_name << "]";
	std::cout << ": Constructor called" << std::endl;
	return ;
}

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "HumanB " << "[" << this->_name << "]";
	std::cout << ": Constructor called" << std::endl;
	return ;
}

HumanB::HumanB(HumanB const &src)
{
	*this = src;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB " << "[" << this->_name << "]";
	std::cout << ": Destructor called" << std::endl;
	return ;
}

HumanB	&HumanB::operator=(HumanB const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return (*this);
}

std::string	const	HumanB::getName(void) const
{
	return (this->_name);
}

std::ostream	&operator<<(std::ostream &o, HumanB const &humanB)
{
	o << "HumanB (Name: " << humanB.getName() << ")" << std::endl;
	return (o);
}
