/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:10:03 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 15:05:57 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default ClapTrap"), _hit_points(10),_max_hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap default constructor called to create :" << std::endl;
    std::cout << "Name : " << this->getName() << std::endl;
    std::cout << "Hit points : " << this->getHitPoints() << std::endl;
    std::cout << "Energy points : " << this->getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << this->getAttackDamage() << std::endl;
    std::cout << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _max_hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap parametric constructor called to create : " << std::endl;
    std::cout << "Name : " << this->getName() << std::endl;
    std::cout << "Hit points : " << this->getHitPoints() << std::endl;
    std::cout << "Energy points : " << this->getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << this->getAttackDamage() << std::endl;
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
    std::cout << "ClapTrap destructor called to destroy " << this->getName() << std::endl;
    return ;
}

ClapTrap    &ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hit_points = rhs._hit_points;
        this->_max_hit_points = rhs._max_hit_points;
        this->_energy_points = rhs._energy_points;
        this->_attack_damage = rhs._attack_damage;
    }
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->getHitPoints() == 0)
    {
        std::cout << "ClapTrap " << this->getName() << " can't attack because it has no more hit points left !" << std::endl;
        return ;
    }
    if (this->getEnergyPoints() == 0)
    {
        std::cout << "ClapTrap " << this->getName() << " can't attack because it has no more energy points left !" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    this->_energy_points--;
    std::cout << "ClapTrap " << this->getName() << " have now " << this->getEnergyPoints() << " energy points remaining" << std::endl;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHitPoints() == 0)
    {
        std::cout << this->getName() << " can't take damage because it is already dead !" << std::endl;
        return ;
    }
    std::cout << this->getName() << " takes " << amount << " damage" << std::endl;
    if (amount >= this->getHitPoints())
    {
        this->_hit_points = 0;
        std::cout << this->getName() << " is dead !" << std::endl;
    }
    else
        this->_hit_points -= amount;
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getHitPoints() == 0)
    {
        std::cout << this->getName() << " can't be repaired because it has no more hit points left !" << std::endl;
        return ;
    }
    if (this->getEnergyPoints() == 0)
    {
        std::cout << this->getName() << " can't be repaired because it has no more energy points left !" << std::endl;
        return ;
    }
    unsigned int    hit_points_before = this->getHitPoints();
    this->_hit_points += amount;
    if (this->_hit_points > this->getMaxHitPoints())
    {
        this->_hit_points = this->getMaxHitPoints();
    }
    std::cout << this->getName() << " regain " << (this->getHitPoints() - hit_points_before) << " hit points" << std::endl;
    std::cout << this->getName() << " have now " << this->getHitPoints() << " hit points remaining" << std::endl;
    this->_energy_points--;
    std::cout << this->getName() << " have now " << this->getEnergyPoints() << " energy points remaining" << std::endl;
    return ;
}

const std::string &ClapTrap::getName(void) const
{
    return (this->_name);    
}

unsigned int    ClapTrap::getHitPoints(void) const
{
    return (this->_hit_points);
}

unsigned int    ClapTrap::getMaxHitPoints(void) const
{
    return (this->_max_hit_points);
}

unsigned int    ClapTrap::getEnergyPoints(void) const
{
    return (this->_energy_points);
}

unsigned int    ClapTrap::getAttackDamage(void) const
{
    return (this->_attack_damage);
}

std::ostream    &operator<<(std::ostream &o, ClapTrap const &clap_trap)
{
    o << "ClapTrap :" << std::endl;
    o << "Name : " << clap_trap.getName() << std::endl;
    o << "Hit points : " << clap_trap.getHitPoints() << std::endl;
    o << "Energy points : " << clap_trap.getEnergyPoints() << std::endl;
    o << "Attack damage : " << clap_trap.getAttackDamage() << std::endl;
    return (o);
}
