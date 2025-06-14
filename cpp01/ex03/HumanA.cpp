/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:32:24 by julien            #+#    #+#             */
/*   Updated: 2025/06/10 10:40:06 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA : Parametric Constructor called with :" << std::endl;
	std::cout << "_name : " << this->_name << std::endl;
	std::cout << "_weapon : ";
	std::cout << this->_weapon.getType() << std::endl;
	return ;
}

HumanA::HumanA(HumanA const &src) : _name(src._name), _weapon(src._weapon)
{
	std::cout << "HumanA : Copy Constructor called" << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA : Destructor called with :" << std::endl;
	std::cout << "_name : " << this->_name << std::endl;
	std::cout << "_weapon : ";
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

void				HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon.getType() << std::endl;
}

std::ostream	&operator<<(std::ostream &o, HumanA const &humanA)
{
	o << "HumanA :" << std::endl;
	o << "_name : " << humanA.getName() << std::endl;
	o << "_weapon : ";
	o << humanA.getWeapon().getType() << std::endl;
	return (o);
}
