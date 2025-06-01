/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:47:53 by julien            #+#    #+#             */
/*   Updated: 2025/06/01 16:52:25 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(void) : _type("default")
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
	std::string	type = this->_type;
	std::string	&typeREF = type;
	return (typeREF);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}

std::ostream	&operator<<(std::ostream &o, Weapon const &weapon)
{
	o << "Type:\t" << weapon.getType() << std::endl;
	return (o);
}
