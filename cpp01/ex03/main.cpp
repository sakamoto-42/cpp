/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:26:06 by julien            #+#    #+#             */
/*   Updated: 2025/05/31 10:28:23 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

int	main(void)
{
	Weapon	default_weapon;
	Weapon	bat_weapon("bat");

	std::cout << default_weapon;
	std::cout << bat_weapon;
	return (0);
}