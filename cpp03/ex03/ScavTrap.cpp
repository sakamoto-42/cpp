/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:46:58 by julien            #+#    #+#             */
/*   Updated: 2025/06/28 14:43:21 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default ScavTrap")
{
    this->_hit_points = 100;
    this->_max_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    this->ClapTrap::_hit_points = this->_hit_points;
    this->ClapTrap::_max_hit_points = this->_max_hit_points;
    this->ClapTrap::_energy_points = this->_energy_points;
    this->ClapTrap::_attack_damage = this->_attack_damage;
    std::cout << "ScavTrap default constructor called to create :" << std::endl;
    std::cout << "Name : " << this->getName() << std::endl;
    std::cout << "Hit points : " << this->getHitPoints() << std::endl;
    std::cout << "Energy points : " << this->getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << this->getAttackDamage() << std::endl;
    std::cout << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_max_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    this->ClapTrap::_hit_points = this->_hit_points;
    this->ClapTrap::_max_hit_points = this->_max_hit_points;
    this->ClapTrap::_energy_points = this->_energy_points;
    this->ClapTrap::_attack_damage = this->_attack_damage;
    std::cout << "ScavTrap parametric constructor called to create : " << std::endl;
    std::cout << "Name : " << this->getName() << std::endl;
    std::cout << "Hit points : " << this->getHitPoints() << std::endl;
    std::cout << "Energy points : " << this->getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << this->getAttackDamage() << std::endl;
    std::cout << std::endl;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src), _hit_points(src._hit_points), _energy_points(src._energy_points), _attack_damage(src._attack_damage)
{
    std::cout << "ScavTrap copy constructor called to copy " << src.getName() << std::endl;
    return ;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called to destroy " << this->getName() << std::endl;
    return ;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &rhs)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        this->_hit_points = rhs._hit_points;
        this->_max_hit_points = rhs._max_hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
    }
    return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->getHitPoints() == 0)
    {
        std::cout << "ScavTrap " << this->getName() << " can't attack because it has no more hit points left !" << std::endl;
        return ;
    }
    if (this->getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap " << this->getName() << " can't attack because it has no more energy points left !" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    this->ClapTrap::_energy_points--;
    std::cout << "ScavTrap " << this->getName() << " have now " << this->getEnergyPoints() << " energy points remaining" << std::endl;
    return ;
}

void    ScavTrap::guardGate(void)
{
    if (this->getHitPoints() == 0)
    {
        std::cout << "ScavTrap " << this->getName() << " can't guard gate because it has no more hit points left !" << std::endl;
        return ;
    }
    if (this->getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap " << this->getName() << " can't guard gate because it has no more energy points left !" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
    this->ClapTrap::_energy_points--;
    std::cout << "ScavTrap " << this->getName() << " have now " << this->getEnergyPoints() << " energy points remaining" << std::endl;
    return ;
}

std::ostream    &operator<<(std::ostream &o, ScavTrap const &scav_trap)
{
    o << "ScavTrap :" << std::endl;
    o << static_cast<const ClapTrap&>(scav_trap);
    return (o);
}
