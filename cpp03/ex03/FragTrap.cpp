/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:58:15 by julien            #+#    #+#             */
/*   Updated: 2025/06/26 15:41:54 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    this->_name = "Default FragTrap";
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap default constructor called to create :" << std::endl;
    std::cout << "Name : " << this->_name << std::endl;
    std::cout << "Hit points : " << this->_hit_points << std::endl;
    std::cout << "Energy points : " << this->_energy_points << std::endl;
    std::cout << "Attack damage : " << this->_attack_damage << std::endl;
    std::cout << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap parametric constructor called to create : " << std::endl;
    std::cout << "Name : " << this->_name << std::endl;
    std::cout << "Hit points : " << this->_hit_points << std::endl;
    std::cout << "Energy points : " << this->_energy_points << std::endl;
    std::cout << "Attack damage : " << this->_attack_damage << std::endl;
    std::cout << std::endl;
    return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called to copy " << src.getName() << std::endl;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called to destroy " << this->_name << std::endl;
    return ;
}

FragTrap    &FragTrap::operator=(FragTrap const &rhs)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
    }
    return (*this);
}

void    FragTrap::attack(const std::string& target)
{
    if (this->_hit_points <= 0)
    {
        std::cout << "FragTrap " << this->_name << " can't attack because it has no more hit points left !" << std::endl;
        return ;
    }
    if (this->_energy_points <= 0)
    {
        std::cout << "FragTrap " << this->_name << " can't attack because it has no more energy points left !" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    this->_energy_points--;
    std::cout << "FragTrap " << this->_name << " have now " << this->_energy_points << " energy points remaining" << std::endl;
    return ;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " says : \"Secret handshake !\"" << std::endl;
    this->_energy_points --;
    std::cout << "FragTrap " << this->_name << " have now " << this->_energy_points << " energy points remaining" << std::endl;
    return ;
}

std::ostream    &operator<<(std::ostream &o, FragTrap const &frag_trap)
{
    o << "FragTrap :" << std::endl;
    o << static_cast<const ClapTrap&>(frag_trap);
    return (o);
}
