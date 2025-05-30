/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:15:11 by julien            #+#    #+#             */
/*   Updated: 2025/05/30 15:50:16 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <new>
#include "Zombie.hpp"
#include "zombieHorde.hpp"

int	main(void)
{
	Zombie	*horde;
	int		N = 10;
	int		i = 0;
	try
	{
		horde = zombieHorde(N, "Bar");
		std::cout << std::endl;
		if (horde == NULL)
			return (1);
		while (i < N)
		{
			std::cout << horde[i];
			horde[i].announce();
			i++;
		}
		std::cout << std::endl;
		delete[](horde);
		horde = NULL;
	}
	catch(const std::bad_alloc& e)
	{
		(void)e;
		return (1);
	}
	return (0);
}
