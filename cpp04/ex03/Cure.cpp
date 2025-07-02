/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:28 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 15:42:07 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
    return ;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
    std::cout << "Cure copy constructor called" << std::endl;
    return ;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl;
    return ;
}

Cure            &Cure::operator=(Cure const &rhs)
{
    std::cout << "Cure copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        AMateria::operator=(rhs);
    }
    return (*this);
}

void            Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    return ;
}

AMateria        *Cure::clone(void) const
{
    return (new Cure(*this));
}

std::ostream    &operator<<(std::ostream &o, Cure const &cure)
{
    o << "Cure :" << std::endl;
    o << "Type : " << cure.getType() << std::endl;
    return (o);
}
