/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:32:24 by julien            #+#    #+#             */
/*   Updated: 2025/06/01 17:37:44 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA : Constructor called with :" << std::endl;
	std::cout << "_name : " << this->_name << std::endl;
	std::cout << "_weapon type (this->_weapon.getType()) :";
	std::cout << this->_weapon.getType() << std::endl;
	return ;
}

HumanA::HumanA(HumanA const &src) : _name(src._name), _weapon(src._weapon)
{
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA : Destructor called with :" << std::endl;
	std::cout << "_name : " << this->_name << std::endl;
	std::cout << "_weapon type (this->_weapon.getType()) :";
	std::cout << this->_weapon.getType() << std::endl;return ;
}

HumanA	&HumanA::operator=(HumanA const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_weapon = rhs._weapon;
	}
	return (*this);
}

std::string	const	HumanA::getName(void) const
{
	return (this->_name);
}

Weapon	const		&HumanA::getWeapon(void) const
{
	return (this->_weapon);
}

std::ostream	&operator<<(std::ostream &o, HumanA const &humanA)
{
	o << "HumanA :" << std::endl;
	o << "_name (humanA.getName()) : " << humanA.getName() << std::endl;
	o << "_weapon type (humanA.getWeapon().getType()) :";
	o << humanA.getWeapon().getType() << std::endl;
	return (o);
}
