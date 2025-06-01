/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:26:06 by julien            #+#    #+#             */
/*   Updated: 2025/06/01 19:37:42 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon	club = Weapon("a crude spiked club");
		HumanA	bob("Bob", club);
		std::cout << bob << std::endl;
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Weapon	club = Weapon("a crude spiked club");
		HumanB	jim("Jim");
		std::cout << jim << std::endl; // Jim should have no weapon
		jim.setWeapon(club);
		std::cout << jim << std::endl; // Jim should now have the club
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Weapon	weapon = Weapon();	// Uses default constructor for Weapon
		HumanB	humanB;				// Uses default constructor for HumanB
		std::cout << humanB << std::endl;
		humanB.attack();			// Attacks with no weapon
		humanB.setWeapon(weapon);	// Attacks with default weapon
		weapon.setType("sword");
		humanB.setWeapon(weapon);
		std::cout << humanB << std::endl;
		humanB.attack();
	}
	std::cout << std::endl;
    return (0);
}
