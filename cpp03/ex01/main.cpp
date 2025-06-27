/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:01:11 by julien            #+#    #+#             */
/*   Updated: 2025/06/27 11:34:22 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "--- Test ScavTrap Default constructor, Parametric constructor, Copy constructor, Copy assignment operator and Stream insertion operator overload ---" << std::endl;
    ClapTrap    CL4P_TP("CL4P-TP");
    
    ScavTrap    default_scav_trap;
    ScavTrap    SC4V_TP("SC4V-TP");
    ScavTrap    SC4V_TP_clone(SC4V_TP);

    std::cout << std::endl;
    default_scav_trap = SC4V_TP;
    std::cout << std::endl;

    std::cout << CL4P_TP << std::endl;

    std::cout << default_scav_trap << std::endl;
    std::cout << SC4V_TP << std::endl;
    std::cout << SC4V_TP_clone << std::endl;

    std::cout << "--- Test ClapTrap and ScavTrap attack() and takeDamage() ---" << std::endl;
    CL4P_TP.attack(SC4V_TP.getName());
    std::cout << std::endl;
    SC4V_TP.takeDamage(CL4P_TP.getAttackDamage());
    std::cout << std::endl;
    SC4V_TP.attack(CL4P_TP.getName());
    std::cout << std::endl;
    CL4P_TP.takeDamage(SC4V_TP.getAttackDamage());
    std::cout << std::endl;

    std::cout << "--- Test ScavTrap beRepaired() and guardGate() ---" << std::endl;
    SC4V_TP.beRepaired(10);
    std::cout << std::endl;
    SC4V_TP.guardGate();
    std::cout << std::endl;

    std::cout << "--- Test ScavTrap energy points depletion ---" << std::endl;
    unsigned int i = SC4V_TP.getEnergyPoints();
    while (i > 0)
    {
        SC4V_TP.attack("another ScavTrap");
        i--;
    }
    std::cout << std::endl;
    SC4V_TP.attack("a ClapTrap");
    std::cout << std::endl;
    SC4V_TP.beRepaired(10);
    std::cout << std::endl;

    std::cout << "--- Test hit points depletion ---" << std::endl;
    SC4V_TP.takeDamage(SC4V_TP.getHitPoints());
    std::cout << std::endl;
    SC4V_TP.attack("a ClapTrap");
    std::cout << std::endl;
    SC4V_TP.beRepaired(10);
    std::cout << std::endl;
    SC4V_TP.takeDamage(5);
    std::cout << std::endl;
    return (0);
}
