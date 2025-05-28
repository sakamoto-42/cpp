/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:15:24 by julien            #+#    #+#             */
/*   Updated: 2025/05/28 10:25:07 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

bool	ft_is_numeric(const std::string &str)
{
	int	i;

	if (str.empty())
		return (false);
	i = 0;
	while (str[i])
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
		i++;
	}
	return (true);
}
