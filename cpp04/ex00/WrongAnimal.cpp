/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:52:13 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 10:31:51 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
    return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
    return ;
}

WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &rhs)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

std::ostream    &operator<<(std::ostream &o, WrongAnimal const &wrong_animal)
{
    o << "WrongAnimal" << std::endl;
    return (o);
}
