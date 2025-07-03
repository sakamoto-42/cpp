/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:55:18 by julien            #+#    #+#             */
/*   Updated: 2025/07/03 13:50:33 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Character.hpp"

Character::Character(void) : _name("unknown name")
{
    std::cout << "Character default constructor called" << std::endl;
    this->_initInventory();
    return ;
}

Character::Character(std::string name) : _name(name)
{
    std::cout << "Character parametric constructor called" << std::endl;
    this->_initInventory();
    return ;
}

Character::Character(Character const &src) : _name(src._name)
{
    std::cout << "Character copy constructor called" << std::endl;
    this->_copyInventory(src);
    return ;
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
    this->_deleteInventory();
    return ;
}

Character           &Character::operator=(Character const &rhs)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_deleteInventory();
        this->_copyInventory(rhs);
    }
    return (*this);
}

void                Character::equip(AMateria *m)
{
    if (!m)
        return ;
    int i = 0;
    while (i < 4)
    {
        if (!this->_inventory[i])
        {
            this->_inventory[i] = m;
            return ;
        }
        i++;
    }
    return ;
}

void                Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->_inventory[idx])
        {
            this->_inventory[idx] = 0;
        }
    }
    return ;
}

void                Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->_inventory[idx])
        {
            this->_inventory[idx]->use(target);
        }
    }
    return ;
}

std::string const   &Character::getName() const
{
    return (this->_name);
}

void                Character::printInventory(std::ostream &o) const
{
    int i = 0;
    while (i < 4)
    {
        o << "\tSlot " << i << ": ";
        if (this->_inventory[i])
        {
            o << this->_inventory[i]->getType() << std::endl;
        }
        else
        {
            o << "empty" << std::endl;
        }
        i++;
    }
}

void                Character::_initInventory(void)
{
    int i = 0;
    while (i < 4)
    {
        this->_inventory[i] = 0;
        i++;
    }
    return ;
}

void                Character::_copyInventory(Character const &src)
{
    int i = 0;

    while (i < 4)
    {
        if (src._inventory[i])
        {
            this->_inventory[i] = src._inventory[i]->clone();
        }
        else
        {
            this->_inventory[i] = 0;
        }
        i++;
    }
    return ;
}

void                Character::_deleteInventory(void)
{
    int i = 0;

    while (i < 4)
    {
        if (this->_inventory[i])
            delete(this->_inventory[i]);
        i++;
    }
    return ;
}

std::ostream        &operator<<(std::ostream &o, Character const &character)
{
    o << "Character :" << std::endl;
    o << "Name : " << character.getName() << std::endl;
    o << "Inventory :" << std::endl;
    character.printInventory(o);
    return (o);
}
