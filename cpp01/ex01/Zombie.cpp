/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:15:36 by julien            #+#    #+#             */
/*   Updated: 2025/06/10 10:34:55 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Default")
{
	std::cout << this->_name << " : Default Constructor called" << std::endl;
    
	return ;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << name << " : Parametric Constructor called" << std::endl;
    return ;
}

Zombie::Zombie(Zombie const &src)
{
	std::cout << this->get_name() << " : Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " : Destructor called" << std::endl;
	return ;
}

Zombie		&Zombie::operator=(Zombie const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return (*this);
}

void		Zombie::announce(void) const
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

std::string	Zombie::get_name(void) const
{
	return (this->_name);
}

void		Zombie::set_name(std::string name)
{
	this->_name = name;
	return ;
}

std::ostream	&operator<<(std::ostream &o, Zombie const &zombie)
{
	o << "My name is " << zombie.get_name() << std::endl;
	return (o);
}
