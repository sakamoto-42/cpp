/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:15:39 by julien            #+#    #+#             */
/*   Updated: 2025/05/29 17:22:46 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	public:
		Zombie(void);
		//Zombie(...);
		Zombie(Zombie const &src);
		virtual ~Zombie(void);

		Zombie &operator=(Zombie const &rhs);

		//...
	//private:
		//...
};

std::ostream	&operator<<(std::ostream &o, Zombie const &zombie);

#endif
