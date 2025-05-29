/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:15:36 by julien            #+#    #+#             */
/*   Updated: 2025/05/29 17:26:19 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

/*
Zombie::Zombie(...)
{

}
*/

Zombie::Zombie(Zombie const &src)
{
	*this = src;
	return ;
}

Zombie::~Zombie(void)
{
	return ;
}

Zombie	&Zombie::operator=(Zombie const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Zombie const &zombie)
{
	(void)zombie;
	return (o);
}
