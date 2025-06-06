/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:09:03 by julien            #+#    #+#             */
/*   Updated: 2025/05/30 15:41:00 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <string>
#include "Zombie.hpp"
#include "zombieHorde.hpp"

Zombie		*zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	if (N <= 0)
		return (NULL);
	horde = new Zombie[N];
	int	i = 0;
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}
	return (horde);
}
