/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:15:11 by julien            #+#    #+#             */
/*   Updated: 2025/05/30 14:16:51 by julien           ###   ########.fr       */
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

	randomChump("Bar");

	Zombie	zombie_instance("Baz");
	zombie_instance.announce();

	return (0);
}
