/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:10:03 by julien            #+#    #+#             */
/*   Updated: 2025/06/27 09:45:38 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default ClapTrap"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap default constructor called to create :" << std::endl;
    std::cout << "Name : " << this->_name << std::endl;
    std::cout << "Hit points : " << this->_hit_points << std::endl;
    std::cout << "Energy points : " << this->_energy_points << std::endl;
    std::cout << "Attack damage : " << this->_attack_damage << std::endl;
    std::cout << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap parametric constructor called to create : " << std::endl;
    std::cout << "Name : " << this->_name << std::endl;
    std::cout << "Hit points : " << this->_hit_points << std::endl;
    std::cout << "Energy points : " << this->_energy_points << std::endl;
    std::cout << "Attack damage : " << this->_attack_damage << std::endl;
    std::cout << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "ClapTrap copy constructor called to copy " << src.getName() << std::endl;
    *this = src;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called to destroy " << this->_name << std::endl;
    return ;
}

ClapTrap    &ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hit_points = rhs._hit_points;
        this->_energy_points = rhs._energy_points;
        this->_attack_damage = rhs._attack_damage;
    }
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't attack because it has no more hit points left !" << std::endl;
        return ;
    }
    if (this->_energy_points <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't attack because it has no more energy points left !" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    this->_energy_points--;
    std::cout << "ClapTrap " << this->_name << " have now " << this->_energy_points << " energy points remaining" << std::endl;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points == 0)
    {
        std::cout << this->_name << " can't take damage because it is already dead !" << std::endl;
        return ;
    }
    std::cout << this->_name << " takes " << amount << " damage" << std::endl;
    if (amount >= this->_hit_points)
    {
        this->_hit_points = 0;
        std::cout << this->_name << " is dead !" << std::endl;
    }
    else
        this->_hit_points -= amount;
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_points <= 0)
    {
        std::cout << this->_name << " can't be repaired because it has no more hit points left !" << std::endl;
        return ;
    }
    if (this->_energy_points <= 0)
    {
        std::cout << this->_name << " can't be repaired because it has no more energy points left !" << std::endl;
        return ;
    }
    std::cout << this->_name << " regain " << amount << " hit points" << std::endl;
    this->_hit_points += amount;
    std::cout << this->_name << " have now " << this->_hit_points << " hit points remaining" << std::endl;
    this->_energy_points--;
    std::cout << this->_name << " have now " << this->_energy_points << " energy points remaining" << std::endl;
    return ;
}

const std::string &ClapTrap::getName(void) const
{
    return (this->_name);    
}

const unsigned int    ClapTrap::getHitPoints(void) const
{
    return (this->_hit_points);
}

const unsigned int    ClapTrap::getEnergyPoints(void) const
{
    return (this->_energy_points);
}

const unsigned int    ClapTrap::getAttackDamage(void) const
{
    return (this->_attack_damage);
}

std::ostream    &operator<<(std::ostream &o, ClapTrap const &clap_trap)
{
    o << "ClapTrap : " << std::endl;
    o << "Name : " << clap_trap.getName() << std::endl;
    o << "Hit points : " << clap_trap.getHitPoints() << std::endl;
    o << "Energy points : " << clap_trap.getEnergyPoints() << std::endl;
    o << "Attack damage : " << clap_trap.getAttackDamage() << std::endl;
    return (o);
}
