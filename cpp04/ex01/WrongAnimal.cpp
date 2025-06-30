/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:52:13 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 17:29:25 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : type("WrongAnimal")
{
    std::cout << "WrongAnimal copy constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    *this = src;
    return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &rhs)
{
    std::cout << "WrongAnimal copy assignment operator called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "\"My sound is not defined (Wrong Animal) !\"" << std::endl;
	return ;
}

const std::string   &WrongAnimal::getType(void) const
{
    return (this->type);
}

std::ostream    &operator<<(std::ostream &o, WrongAnimal const &wrong_animal)
{
    o << "My type is : " << wrong_animal.getType() << std::endl;
    return (o);
}
