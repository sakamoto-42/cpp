/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:47:53 by julien            #+#    #+#             */
/*   Updated: 2025/06/09 11:24:57 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(void) : _type("default weapon")
{
	std::cout << "Weapon " << "[" << this->_type << "]";
	std::cout << ": Constructor called" << std::endl;
	return ;
}

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon " << "[" << this->_type << "]";
	std::cout << ": Constructor called" << std::endl;
	return ;
}

Weapon::Weapon(Weapon const &src)
{
	std::cout << "Weapon : Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon " << "[" << this->_type << "]";
	std::cout << ": Destructor called" << std::endl;
	return ;
}

Weapon	&Weapon::operator=(Weapon const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

std::string const	&Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	std::cout << "Weapon type set to " << this->_type << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &o, Weapon const &weapon)
{
	o << "Type:\t" << weapon.getType() << std::endl;
	return (o);
}
