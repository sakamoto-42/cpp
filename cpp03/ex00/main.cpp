/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:01:11 by julien            #+#    #+#             */
/*   Updated: 2025/06/25 16:28:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    {
        std::cout << "--- Test Default constructor, Parametric constructor, Copy constructor, Copy assignment operator, Stream insertion operator overload and Destructor ---" << std::endl;
        ClapTrap    default_clap_trap;
        ClapTrap    CL4P_TP("CL4P-TP");
        ClapTrap    CLP4P_TP_clone(CL4P_TP);

        default_clap_trap = CL4P_TP;
        std::cout << CL4P_TP << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << "--- Test attack(), takeDamage() and beRepaired() ---" << std::endl;
        ClapTrap    clap_trap_1("CL4P-TP 1");
        ClapTrap    clap_trap_2("CL4P-TP 2");

        clap_trap_1.attack(clap_trap_2.getName());
        std::cout << std::endl;
        clap_trap_2.takeDamage(clap_trap_1.getAttackDamage());
        std::cout << std::endl;
        clap_trap_2.takeDamage(5);
        std::cout << std::endl;
        clap_trap_2.beRepaired(5);
        std::cout << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << "--- Test energy points depletion ---" << std::endl;
        ClapTrap    clap_trap("CL4P-TP");

        int i = 0;
        while (i < 10)
        {
            clap_trap.attack("another ClapTrap");
            i++;
        }
        std::cout << std::endl;
        clap_trap.attack("another ClapTrap");
        std::cout << std::endl;
        clap_trap.beRepaired(5);
        std::cout << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << "--- Test hit points depletion ---" << std::endl;
        ClapTrap    clap_trap_3("CL4P-TP 3");
        ClapTrap    clap_trap_4("CL4P-TP 4");

        clap_trap_3.attack(clap_trap_4.getName());
        std::cout << std::endl;
        clap_trap_4.takeDamage(15);
        std::cout << std::endl;
        clap_trap_4.attack(clap_trap_3.getName());
        std::cout << std::endl;
        clap_trap_4.beRepaired(10);
        std::cout << std::endl;
        clap_trap_4.takeDamage(5);
        std::cout << std::endl;
    }
    return (0);
}
