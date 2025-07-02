/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:28 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 14:52:07 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cure.hpp"

Cure::Cure(void)
{
    std::cout << "Cure default constructor called" << std::endl;
    return ;
}

Cure::Cure(Cure const &src)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = src;
    return ;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl;
    return ;
}

Cure  &Cure::operator=(Cure const &rhs)
{
    std::cout << "Cure copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

/*
void    AMateria::use(ICharacter &target)
{
    if (this->_type == "ice")
    {
        std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
        return ;
    }
    if (this->_type == "cure")
    {
        std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
        return ;
    }
    return ;
}
*/

std::ostream    &operator<<(std::ostream &o, Cure const &cure)
{
    (void)cure;
    o << "Cure" << std::endl;
    return (o);
}
