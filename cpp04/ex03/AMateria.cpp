/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:24 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 15:42:06 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default")
{
    std::cout << "AMateria default constructor called" << std::endl;
    return ;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "AMateria parametric constructor called with :" << std::endl;
    std::cout << this->getType();
    return ;
}

AMateria::AMateria(AMateria const &src) : _type(src._type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    return ;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor called" << std::endl;
    return ;
}

AMateria            &AMateria::operator=(AMateria const &rhs)
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

void                AMateria::use(ICharacter &target)
{
    std::cout << "* use an unknown materia on " << target.getName() << "*" << std::endl;
    return ;
}

std::string const   &AMateria::getType() const
{
    return (this->_type);
}

std::ostream        &operator<<(std::ostream &o, AMateria const &a_materia)
{
    o << "AMateria :" << std::endl;
    o << "Type : " << a_materia.getType() << std::endl;
    return (o);
}
