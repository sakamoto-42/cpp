/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:01:11 by julien            #+#    #+#             */
/*   Updated: 2025/06/28 08:37:03 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
    {
        std::cout << "--- TESTS SCAVTRAP AND FRAGTRAP ---" << std::endl;
        std::cout << "--- Test ScavTrap and FragTrap Default constructor, Parametric constructor, Copy constructor, Copy assignment operator and Stream insertion operator overload ---" << std::endl;
        ClapTrap    CL4P_TP("CL4P-TP");
        
        ScavTrap    default_scav_trap;
        FragTrap    default_frag_trap;
        ScavTrap    SC4V_TP("SC4V-TP");
        FragTrap    FR4G_TP("FR4G-TP");
        ScavTrap    SC4V_TP_clone(SC4V_TP);
        std::cout << std::endl;
        FragTrap    FR4G_TP_clone(FR4G_TP);

        std::cout << std::endl;
        default_frag_trap = FR4G_TP;
        std::cout << std::endl;

        std::cout << CL4P_TP << std::endl;
        std::cout << SC4V_TP << std::endl;

        std::cout << default_frag_trap << std::endl;
        std::cout << FR4G_TP << std::endl;
        std::cout << FR4G_TP_clone << std::endl;

        std::cout << "--- Test ScavTrap and FragTrap attack() and takeDamage() ---" << std::endl;
        SC4V_TP.attack(FR4G_TP.getName());
        std::cout << std::endl;
        FR4G_TP.takeDamage(SC4V_TP.getAttackDamage());
        std::cout << std::endl;
        FR4G_TP.attack(SC4V_TP.getName());
        std::cout << std::endl;
        SC4V_TP.takeDamage(FR4G_TP.getAttackDamage());
        std::cout << std::endl;

        std::cout << "--- Test ScavTrap and FragTrap beRepaired(), ScavTrap guardGate() and FragTrap highFivesGuys() ---" << std::endl;
        SC4V_TP.beRepaired(10);
        std::cout << std::endl;
        FR4G_TP.beRepaired(10);
        std::cout << std::endl;
        SC4V_TP.guardGate();
        std::cout << std::endl;
        FR4G_TP.highFivesGuys();
        std::cout << std::endl;

        std::cout << "--- Test FragTrap energy points depletion ---" << std::endl;
        unsigned int i = FR4G_TP.getEnergyPoints();
        while (i > 0)
        {
            FR4G_TP.attack("another FragTrap");
            i--;
        }
        std::cout << std::endl;
        FR4G_TP.attack("a ClapTrap");
        std::cout << std::endl;
        FR4G_TP.beRepaired(10);
        std::cout << std::endl;
        FR4G_TP.highFivesGuys();
        std::cout << std::endl;

        std::cout << "--- Test hit points depletion ---" << std::endl;
        FR4G_TP.takeDamage(FR4G_TP.getHitPoints());
        std::cout << std::endl;
        FR4G_TP.attack("a ClapTrap");
        std::cout << std::endl;
        FR4G_TP.beRepaired(10);
        std::cout << std::endl;
        FR4G_TP.highFivesGuys();
        std::cout << std::endl;
        FR4G_TP.takeDamage(5);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "--- TESTS DIAMONDTRAP ---" << std::endl;
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
    }
    return (0);
}
