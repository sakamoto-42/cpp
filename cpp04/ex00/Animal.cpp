/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:33:10 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 17:11:01 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
    std::cout << "Animal default constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Animal::Animal(Animal const &src) : type("Animal")
{
    std::cout << "Animal copy constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    *this = src;
    return ;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Animal  &Animal::operator=(Animal const &rhs)
{
    std::cout << "Animal copy assignment operator called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << "\"My sound is not defined !\"" << std::endl;
	return ;
}

const std::string   &Animal::getType(void) const
{
    return (this->type);
}

std::ostream    &operator<<(std::ostream &o, Animal const &animal)
{
    o << "My type is : " << animal.getType() << std::endl;
    return (o);
}
