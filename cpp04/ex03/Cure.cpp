/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:28 by julien            #+#    #+#             */
/*   Updated: 2025/07/01 01:03:06 by julien           ###   ########.fr       */
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

std::ostream    &operator<<(std::ostream &o, Cure const &cure)
{
    (void)cure;
    o << "Cure" << std::endl;
    return (o);
}
