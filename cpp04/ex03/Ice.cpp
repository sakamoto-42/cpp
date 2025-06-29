/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:35 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 10:34:53 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Ice.hpp"

Ice::Ice(void)
{
    std::cout << "Ice default constructor called" << std::endl;
    return ;
}

Ice::Ice(Ice const &src)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = src;
    return ;
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor called" << std::endl;
    return ;
}

Ice  &Ice::operator=(Ice const &rhs)
{
    std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

std::ostream    &operator<<(std::ostream &o, Ice const &ice)
{
    o << "Ice" << std::endl;
    return (o);
}
