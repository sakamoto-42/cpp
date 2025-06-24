/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:01:11 by julien            #+#    #+#             */
/*   Updated: 2025/06/24 11:17:10 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main(void)
{
    {
        ClapTrap    default_clap_trap;
        ClapTrap    CL4P_TP("CL4P-TP");
        ClapTrap    CLP4P_TP_clone(CL4P_TP);

        default_clap_trap = CL4P_TP;
    }
    {
        std::cout << std::endl;
        ClapTrap    clap_trap_1("CL4P-TP 1");
        ClapTrap    clap_trap_2("CL4P-TP 2");

        clap_trap_1.attack(clap_trap_2.getName());
        clap_trap_2.takeDamage(clap_trap_1.getAttackDamage());
        clap_trap_2.beRepaired(5);
    }
    {
        std::cout << std::endl;
        ClapTrap    clap_trap("CL4P-TP");

        int i = 0;
        while (i < 10)
        {
            clap_trap.attack("another ClapTrap");
            i++;
        }
        clap_trap.attack("another ClapTrap");
        clap_trap.beRepaired(5);
    }
    {
        std::cout << std::endl;
        ClapTrap    clap_trap_3("CL4P-TP 3");
        ClapTrap    clap_trap_4("CL4P-TP 4");

        clap_trap_3.attack(clap_trap_4.getName());
        clap_trap_4.takeDamage(15);
        clap_trap_4.attack(clap_trap_3.getName());
        clap_trap_4.beRepaired(10);
        clap_trap_4.takeDamage(5);
    }
    return (0);
}
