/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:15:39 by julien            #+#    #+#             */
/*   Updated: 2025/05/30 14:38:43 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		Zombie(Zombie const &src);
		virtual ~Zombie(void);

		Zombie &operator=(Zombie const &rhs);

		void		announce(void) const;

		std::string	get_name(void) const;

	private:
		std::string	_name;
};

std::ostream	&operator<<(std::ostream &o, Zombie const &zombie);

#endif
