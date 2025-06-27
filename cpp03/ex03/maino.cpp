/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:01:11 by julien            #+#    #+#             */
/*   Updated: 2025/06/27 20:35:51 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "--- Test Default constructor, Parametric constructor, Copy constructor, Copy assignment operator and Stream insertion operator overload ---" << std::endl;
    DiamondTrap default_diamond_trap;
    DiamondTrap DI4MD_TP("DI4MD-TP");
    DiamondTrap DI4MD_TP_clone(DI4MD_TP);
    
    std::cout << std::endl;
    default_diamond_trap = DI4MD_TP;
    std::cout << std::endl;

    std::cout << default_diamond_trap << std::endl;
    std::cout << DI4MD_TP << std::endl;
    std::cout << DI4MD_TP_clone << std::endl;

    std::cout << "--- Test attack() and takeDamage() ---" << std::endl;
    DI4MD_TP.attack(DI4MD_TP.getName());
    std::cout << std::endl;
    DI4MD_TP.takeDamage(DI4MD_TP.getAttackDamage());
    std::cout << std::endl;
    DI4MD_TP.attack(DI4MD_TP.getName());
    std::cout << std::endl;
    DI4MD_TP.takeDamage(DI4MD_TP.getAttackDamage());
    std::cout << std::endl;

    std::cout << "--- Test beRepaired(), guardGate(), highFivesGuys() and whoAmI()---" << std::endl;
    DI4MD_TP.beRepaired(10);
    std::cout << std::endl;
    DI4MD_TP.beRepaired(10);
    std::cout << std::endl;
    DI4MD_TP.guardGate();
    std::cout << std::endl;
    DI4MD_TP.highFivesGuys();
    std::cout << std::endl;
    DI4MD_TP.whoAmI();
    std::cout << std::endl;

    std::cout << "--- Test energy points depletion ---" << std::endl;
    unsigned int i = DI4MD_TP.getEnergyPoints();
    while (i > 0)
    {
        DI4MD_TP.attack("another DiamondTrap");
        i--;
    }
    std::cout << std::endl;
    DI4MD_TP.attack("another DiamondTrap");
    std::cout << std::endl;
    DI4MD_TP.beRepaired(10);
    std::cout << std::endl;
    DI4MD_TP.highFivesGuys();
    std::cout << std::endl;
    DI4MD_TP.guardGate();
    std::cout << std::endl;

    std::cout << "--- Test hit points depletion ---" << std::endl;
    DI4MD_TP.takeDamage(DI4MD_TP.getHitPoints());
    std::cout << std::endl;
    DI4MD_TP.attack("another DiamondTrap");
    std::cout << std::endl;
    DI4MD_TP.beRepaired(10);
    std::cout << std::endl;
    DI4MD_TP.highFivesGuys();
    std::cout << std::endl;
    DI4MD_TP.guardGate();
    std::cout << std::endl;
    DI4MD_TP.takeDamage(5);
    std::cout << std::endl;
    return (0);
}
