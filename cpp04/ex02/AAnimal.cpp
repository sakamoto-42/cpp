/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:32:35 by julien            #+#    #+#             */
/*   Updated: 2025/06/30 23:33:37 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
    std::cout << "AAnimal default constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

AAnimal::AAnimal(AAnimal const &src)
{
    std::cout << "AAnimal copy constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    *this = src;
    return ;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal destructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

AAnimal  &AAnimal::operator=(AAnimal const &rhs)
{
    std::cout << "AAnimal copy assignment operator called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return (*this);
}

const std::string   &AAnimal::getType(void) const
{
    return (this->type);
}

std::ostream    &operator<<(std::ostream &o, AAnimal const &a_animal)
{
    o << "My type is : " << a_animal.getType() << std::endl;
    return (o);
}
