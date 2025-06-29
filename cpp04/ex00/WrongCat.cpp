/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:47:21 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 10:31:42 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat default constructor called" << std::endl;
    return ;
}

WrongCat::WrongCat(WrongCat const &src)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
    return ;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
    return ;
}

WrongCat  &WrongCat::operator=(WrongCat const &rhs)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

std::ostream    &operator<<(std::ostream &o, WrongCat const &wrong_cat)
{
    o << "WrongCat" << std::endl;
    return (o);
}
