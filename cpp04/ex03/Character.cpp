/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:55:18 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 16:18:05 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Character.hpp"

Character::Character(void)
{
    std::cout << "Character default constructor called" << std::endl;
    return ;
}

Character::Character(std::string name) : _name(name)
{
    std::cout << "Character parametric constructor called" << std::endl;
    return ;
}

Character::Character(Character const &src)
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = src;
    return ;
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
    return ;
}

Character           &Character::operator=(Character const &rhs)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

std::string const   &Character::getName() const
{
    return (this->_name);
}

void                Character::equip(AMateria *m)
{
    (void)m;
    return ;
}

void                Character::unequip(int idx)
{
    (void)idx;
    return ;
}
void                Character::use(int idx, ICharacter &target)
{
    (void)idx;
    (void)target;
    return ;
}

std::ostream        &operator<<(std::ostream &o, Character const &character)
{
    (void)character;
    o << "Character" << std::endl;
    return (o);
}
