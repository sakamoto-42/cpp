/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:36:39 by julien            #+#    #+#             */
/*   Updated: 2025/06/09 11:25:58 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(void) : _name("default name"), _weapon(NULL)
{
	std::cout << "HumanB : Default Constructor called with :" << std::endl;
	std::cout << "_name : " << this->_name << std::endl;
	std::cout << "_weapon : ";
	if (this->_weapon == NULL)
		std::cout << "NULL" << std::endl;
	else
		std::cout << this->_weapon->getType() << std::endl;
	return ;
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << "HumanB : Constructor called with :" << std::endl;
	std::cout << "_name : " << this->_name << std::endl;
	std::cout << "_weapon : ";
	if (this->_weapon == NULL)
		std::cout << "NULL" << std::endl;
	else
		std::cout << this->_weapon->getType() << std::endl;
	return ;
}

HumanB::HumanB(HumanB const &src) : _name(src._name), _weapon(src._weapon)
{
	std::cout << "HumanB : Copy Constructor called" << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB : Destructor called with :" << std::endl;
	std::cout << "_name : " << this->_name << std::endl;
	std::cout << "_weapon : ";
	if (this->_weapon == NULL)
		std::cout << "NULL" << std::endl;
	else
		std::cout << this->_weapon->getType() << std::endl;
	return ;
}

HumanB	&HumanB::operator=(HumanB const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_weapon = rhs._weapon;
	}
	return (*this);
}

std::string	const	HumanB::getName(void) const
{
	return (this->_name);
}

Weapon	const		*HumanB::getWeapon(void) const
{
	return (this->_weapon);
}

void				HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	std::cout << "HumanB equips a " << this->_weapon->getType() << std::endl;
	return ;
}

void				HumanB::attack(void) const
{
	std::cout << this->_name;
	if (this->_weapon == NULL)
	{
		std::cout << " tries to attack, but has no weapon !" << std::endl;
	}
	else
	{
		std::cout << " attacks with their ";
		std::cout << this->_weapon->getType() << std::endl;
	}
	return ;
}

std::ostream	&operator<<(std::ostream &o, HumanB const &humanB)
{
	o << "HumanB :" << std::endl;
	o << "_name : " << humanB.getName() << std::endl;
	o << "_weapon : ";
	if (humanB.getWeapon() == NULL)
		o << "NULL" << std::endl;
	else
		o << humanB.getWeapon()->getType() << std::endl;
	return (o);
}
