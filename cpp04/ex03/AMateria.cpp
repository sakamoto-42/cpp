/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:24 by julien            #+#    #+#             */
/*   Updated: 2025/07/01 01:12:01 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(void)
{
    std::cout << "AMateria default constructor called" << std::endl;
    return ;
}

AMateria::AMateria(std::string const &type)
{
    return ;
}

AMateria::AMateria(AMateria const &src)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
    return ;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor called" << std::endl;
    return ;
}

AMateria  &AMateria::operator=(AMateria const &rhs)
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

void    AMateria::use(ICharacter &target)
{
    if (type == "ice")
    {
        std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
        return ;
    }
    if (type == "cure")
    {
        std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
        return ;
    }
    return ;
}

std::string const   &AMateria::getType() const
{
    return (this->type);
}

std::ostream        &operator<<(std::ostream &o, AMateria const &a_materia)
{
    o << "AMateria" << std::endl;
    return (o);
}
