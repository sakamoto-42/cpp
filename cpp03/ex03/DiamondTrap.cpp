/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:42:59 by julien            #+#    #+#             */
/*   Updated: 2025/06/28 14:41:14 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_DiamondTrap_clap_name"), ScavTrap("Default ScavTrap"), FragTrap("Default FragTrap"), _name("Default DiamondTrap")
{
    this->ClapTrap::_hit_points = this->FragTrap::_hit_points;
    this->ClapTrap::_max_hit_points = this->FragTrap::_max_hit_points;
    this->ClapTrap::_energy_points = this->ScavTrap::_energy_points;
    this->ClapTrap::_attack_damage = this->FragTrap::_attack_damage;
    std::cout << "DiamondTrap default constructor called to create :" << std::endl;
    std::cout << "Name : " << this->getName() << std::endl;
    std::cout << "Hit points : " << this->getHitPoints() << std::endl;
    std::cout << "Energy points : " << this->getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << this->getAttackDamage() << std::endl;
    std::cout << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    this->ClapTrap::_hit_points = this->FragTrap::_hit_points;
    this->ClapTrap::_max_hit_points = this->FragTrap::_max_hit_points;
    this->ClapTrap::_energy_points = this->ScavTrap::_energy_points;
    this->ClapTrap::_attack_damage = this->FragTrap::_attack_damage;
    std::cout << "DiamondTrap parametric constructor called to create :" << std::endl;
    std::cout << "Name : " << this->getName() << std::endl;
    std::cout << "Hit points : " << this->getHitPoints() << std::endl;
    std::cout << "Energy points : " << this->getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << this->getAttackDamage() << std::endl;
    std::cout << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
    std::cout << "DiamondTrap copy constructor called to copy " << src.getName() << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called to destroy " << this->getName() << std::endl;
    return ;
}

DiamondTrap    &DiamondTrap::operator=(DiamondTrap const &rhs)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        this->_name = rhs._name;
    }
    return (*this);
}

void    DiamondTrap::attack(const std::string& target)
{
    std::cout << "DiamondTrap attack() member function called with " << target << std::endl;
    ScavTrap::attack(target);
    return ;
}

void    DiamondTrap::whoAmI(void) const
{
    std::cout << "My DiamondTrap name is : " << this->getName() << std::endl;
    std::cout << "My ClapTrap name is : " << ClapTrap::getName() << std::endl;
}

const std::string &DiamondTrap::getName(void) const
{
    return (this->_name);
}

unsigned int    DiamondTrap::getHitPoints(void) const
{
    return (this->ClapTrap::_hit_points);
}

unsigned int    DiamondTrap::getMaxHitPoints(void) const
{
    return (this->ClapTrap::_max_hit_points);
}

unsigned int    DiamondTrap::getEnergyPoints(void) const
{
    return (this->ClapTrap::_energy_points);
}

unsigned int    DiamondTrap::getAttackDamage(void) const
{
    return (this->ClapTrap::_attack_damage);
}

std::ostream    &operator<<(std::ostream &o, DiamondTrap const &diamond_trap)
{
    o << "DiamondTrap :" << std::endl;
    o << "Name : " << diamond_trap.getName() << std::endl;
    o << static_cast<const ClapTrap&>(diamond_trap);
    return (o);
}
