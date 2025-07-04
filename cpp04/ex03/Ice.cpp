/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:35 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 15:53:50 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
    return ;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
    std::cout << "Ice copy constructor called" << std::endl;
    return ;
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor called" << std::endl;
    return ;
}

Ice             &Ice::operator=(Ice const &rhs)
{
    std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        AMateria::operator=(rhs);
    }
    return (*this);
}

void            Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return ;
}

AMateria        *Ice::clone(void) const
{
    return (new Ice(*this));
}

std::ostream    &operator<<(std::ostream &o, Ice const &ice)
{
    o << "Ice :" << std::endl;
    o << "Type : " << ice.getType() << std::endl;
    return (o);
}
