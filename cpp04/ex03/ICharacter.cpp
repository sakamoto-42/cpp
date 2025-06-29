/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:38 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 10:35:27 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
    std::cout << "ICharacter default constructor called" << std::endl;
    return ;
}

ICharacter::ICharacter(ICharacter const &src)
{
    std::cout << "ICharacter copy constructor called" << std::endl;
    *this = src;
    return ;
}

ICharacter::~ICharacter(void)
{
    std::cout << "ICharacter destructor called" << std::endl;
    return ;
}

ICharacter  &ICharacter::operator=(ICharacter const &rhs)
{
    std::cout << "ICharacter copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

std::ostream    &operator<<(std::ostream &o, ICharacter const &i_character)
{
    o << "ICharacter" << std::endl;
    return (o);
}
