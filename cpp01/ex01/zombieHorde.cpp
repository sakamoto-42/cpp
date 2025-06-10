/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:09:03 by julien            #+#    #+#             */
/*   Updated: 2025/06/10 10:37:59 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <string>
#include "Zombie.hpp"
#include "zombieHorde.hpp"

Zombie		*zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	int	i;

	if (N <= 0)
		return (NULL);
	horde = new Zombie[N];
	if (!horde)
		return (NULL);
	i = 0;
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}
	return (horde);
}
