/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:15:11 by julien            #+#    #+#             */
/*   Updated: 2025/05/30 14:37:45 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "newZombie.hpp"
#include "randomChump.hpp"

int	main(void)
{
	Zombie	*new_zombie;

	new_zombie = newZombie("Foo");
	std::cout << *new_zombie;
	new_zombie->announce();
	delete(new_zombie);
	std::cout << std::endl;
	randomChump("Bar");
	std::cout << std::endl;
	Zombie	zombie_instance("Baz");
	zombie_instance.announce();
	std::cout << std::endl;
	Zombie	zombie_default_instance;
	zombie_default_instance.announce();
	std::cout << std::endl;
	return (0);
}
