/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:42 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 10:35:49 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
    std::cout << "IMateriaSource default constructor called" << std::endl;
    return ;
}

IMateriaSource::IMateriaSource(IMateriaSource const &src)
{
    std::cout << "IMateriaSource copy constructor called" << std::endl;
    *this = src;
    return ;
}

IMateriaSource::~IMateriaSource(void)
{
    std::cout << "IMateriaSource destructor called" << std::endl;
    return ;
}

IMateriaSource  &IMateriaSource::operator=(IMateriaSource const &rhs)
{
    std::cout << "IMateriaSource copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

std::ostream    &operator<<(std::ostream &o, IMateriaSource const &i_materia_source)
{
    o << "IMateriaSource" << std::endl;
    return (o);
}
