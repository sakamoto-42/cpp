/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:50:44 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 17:18:11 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    this->type = "Cat";
    std::cout << "Cat default constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Cat::Cat(Cat const &src) : Animal(src)
{
    this->type = "Cat";
    std::cout << "Cat copy constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    *this = src;
    return ;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Cat  &Cat::operator=(Cat const &rhs)
{
    std::cout << "Cat copy assignment operator called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
    }
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "\"Meow !\"" << std::endl;
	return ;
}

std::ostream    &operator<<(std::ostream &o, Cat const &cat)
{
    o << static_cast<const Animal&>(cat);
    return (o);
}
