/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:51:24 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 17:18:19 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->type = "Dog";
    std::cout << "Dog default constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Dog::Dog(Dog const &src) : Animal(src)
{
    this->type = "Dog";
    std::cout << "Dog copy constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    *this = src;
    return ;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Dog  &Dog::operator=(Dog const &rhs)
{
    std::cout << "Dog copy assignment operator called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "\"Waf !\"" << std::endl;
	return ;
}

std::ostream    &operator<<(std::ostream &o, Dog const &dog)
{
    o << static_cast<const Animal&>(dog);
    return (o);
}
