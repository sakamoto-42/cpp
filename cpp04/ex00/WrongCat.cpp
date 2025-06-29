/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:47:21 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 17:29:04 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called wtih :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
    this->type = "WrongCat";
    std::cout << "WrongCat copy constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    *this = src;
    return ;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

WrongCat  &WrongCat::operator=(WrongCat const &rhs)
{
    std::cout << "WrongCat copy assignment operator called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    if (this != &rhs)
    {
        WrongAnimal::operator=(rhs);
    }
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "\"Meow !\"" << std::endl;
	return ;
}

std::ostream    &operator<<(std::ostream &o, WrongCat const &wrong_cat)
{
    o << static_cast<const WrongAnimal&>(wrong_cat);
    return (o);
}
