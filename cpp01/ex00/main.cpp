/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:15:11 by julien            #+#    #+#             */
/*   Updated: 2025/06/10 10:28:24 by juduchar         ###   ########.fr       */
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
	std::cout << zombie_instance;
	zombie_instance.announce();
	std::cout << std::endl;

	Zombie	zombie_default_instance;
	std::cout << zombie_default_instance;
	zombie_default_instance.announce();
	std::cout << std::endl;
	return (0);
}
