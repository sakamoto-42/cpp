/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:26:06 by julien            #+#    #+#             */
/*   Updated: 2025/06/10 10:49:19 by juduchar         ###   ########.fr       */
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
		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");
		jim.setWeapon(club);
		std::cout << jim << std::endl;
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Weapon	weapon = Weapon();
		HumanB	humanB;
		humanB.attack();
		humanB.setWeapon(weapon);
		std::cout << humanB << std::endl;
		humanB.attack();
		weapon.setType("sword");
		humanB.setWeapon(weapon);
		std::cout << humanB << std::endl;
		humanB.attack();
	}
    return (0);
}
