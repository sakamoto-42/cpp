/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:10:03 by julien            #+#    #+#             */
/*   Updated: 2025/06/23 12:31:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    *this = src;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    return ;
}

ClapTrap    &ClapTrap::operator=(ClapTrap const &rhs)
{
    if (this != &rhs)
    {
        
    }
    return (*this);
}

std::ostream    &operator<<(std::ostream &o, ClapTrap const &clap_trap)
{
    return (o);
}
