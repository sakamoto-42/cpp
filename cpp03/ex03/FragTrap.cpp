/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:58:15 by julien            #+#    #+#             */
/*   Updated: 2025/06/28 09:10:26 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default FragTrap")
{
    this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
    this->ClapTrap::_hit_points = this->getHitPoints();
    this->ClapTrap::_energy_points = this->getEnergyPoints();
    this->ClapTrap::_attack_damage = this->getAttackDamage();
    std::cout << "FragTrap default constructor called to create :" << std::endl;
    std::cout << "Name : " << this->getName() << std::endl;
    std::cout << "Hit points : " << this->getHitPoints() << std::endl;
    std::cout << "Energy points : " << this->getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << this->getAttackDamage() << std::endl;
    std::cout << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
    this->ClapTrap::_hit_points = this->getHitPoints();
    this->ClapTrap::_energy_points = this->getEnergyPoints();
    this->ClapTrap::_attack_damage = this->getAttackDamage();
    std::cout << "FragTrap parametric constructor called to create : " << std::endl;
    std::cout << "Name : " << this->getName() << std::endl;
    std::cout << "Hit points : " << this->getHitPoints() << std::endl;
    std::cout << "Energy points : " << this->getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << this->getAttackDamage() << std::endl;
    std::cout << std::endl;
    return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src), _hit_points(src._hit_points), _energy_points(src._energy_points), _attack_damage(src._attack_damage)
{
    std::cout << "FragTrap copy constructor called to copy " << src.getName() << std::endl;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called to destroy " << this->getName() << std::endl;
    return ;
}

FragTrap    &FragTrap::operator=(FragTrap const &rhs)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
    }
    return (*this);
}

void    FragTrap::attack(const std::string& target)
{
    if (this->getHitPoints() <= 0)
    {
        std::cout << "FragTrap " << this->getName() << " can't attack because it has no more hit points left !" << std::endl;
        return ;
    }
    if (this->getEnergyPoints() <= 0)
    {
        std::cout << "FragTrap " << this->getName() << " can't attack because it has no more energy points left !" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    this->ClapTrap::_energy_points--;
    std::cout << "FragTrap " << this->getName() << " have now " << this->getEnergyPoints() << " energy points remaining" << std::endl;
    return ;
}

void    FragTrap::highFivesGuys(void)
{
    if (this->getHitPoints() <= 0)
    {
        std::cout << "FragTrap " << this->getName() << " can't high five because it has no more hit points left !" << std::endl;
        return ;
    }
    if (this->getEnergyPoints() <= 0)
    {
        std::cout << "FragTrap " << this->getName() << " can't high five because it has no more energy points left !" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->getName() << " says : \"Secret handshake !\"" << std::endl;
    this->ClapTrap::_energy_points--;
    std::cout << "FragTrap " << this->getName() << " have now " << this->getEnergyPoints() << " energy points remaining" << std::endl;
    return ;
}

std::ostream    &operator<<(std::ostream &o, FragTrap const &frag_trap)
{
    o << "FragTrap :" << std::endl;
    o << static_cast<const ClapTrap&>(frag_trap);
    return (o);
}
