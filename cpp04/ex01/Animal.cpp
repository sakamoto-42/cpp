/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:33:10 by julien            #+#    #+#             */
/*   Updated: 2025/06/30 23:42:43 by julien           ###   ########.fr       */
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

Animal::Animal(Animal const &src)
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

void    Animal::learn(const std::string &idea)
{
    (void)idea;
    std::cout << "The Animal class don't have a Brain, so can't learn an idea !" << std::endl;
}

const std::string   Animal::recall(int idea_index) const
{
    (void)idea_index;
    return ("The Animal class don't have a Brain, so can't recall an idea !");
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
