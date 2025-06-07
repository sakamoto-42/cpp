/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:24:44 by julien            #+#    #+#             */
/*   Updated: 2025/06/07 10:44:43 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char *argv[])
{
	char	*ptr;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 1;
	while (i < argc)
	{
		ptr = argv[i];
		while (*ptr)
		{
			std::cout << (char)toupper(*ptr);
			ptr++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
