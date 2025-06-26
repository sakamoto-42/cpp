/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:46:58 by julien            #+#    #+#             */
/*   Updated: 2025/06/25 15:38:29 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->_name = "Default ScavTrap";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap default constructor called to create :" << std::endl;
    std::cout << "Name : " << this->_name << std::endl;
    std::cout << "Hit points : " << this->_hit_points << std::endl;
    std::cout << "Energy points : " << this->_energy_points << std::endl;
    std::cout << "Attack damage : " << this->_attack_damage << std::endl;
    std::cout << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap parametric constructor called to create : " << std::endl;
    std::cout << "Name : " << this->_name << std::endl;
    std::cout << "Hit points : " << this->_hit_points << std::endl;
    std::cout << "Energy points : " << this->_energy_points << std::endl;
    std::cout << "Attack damage : " << this->_attack_damage << std::endl;
    std::cout << std::endl;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
    std::cout << "ScavTrap copy constructor called to copy " << src.getName() << std::endl;
    return ;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called to destroy " << this->_name << std::endl;
    return ;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &rhs)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
    }
    return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_hit_points <= 0)
    {
        std::cout << "ScavTrap " << this->_name << " can't attack because it has no more hit points left !" << std::endl;
        return ;
    }
    if (this->_energy_points <= 0)
    {
        std::cout << "ScavTrap " << this->_name << " can't attack because it has no more energy points left !" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    this->_energy_points--;
    std::cout << "ScavTrap " << this->_name << " have now " << this->_energy_points << " energy points remaining" << std::endl;
    return ;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
    this->_energy_points --;
    std::cout << "ScavTrap " << this->_name << " have now " << this->_energy_points << " energy points remaining" << std::endl;
    return ;
}

std::ostream    &operator<<(std::ostream &o, ScavTrap const &scav_trap)
{
    o << "ScavTrap :" << std::endl;
    o << static_cast<const ClapTrap&>(scav_trap);
    return (o);
}
