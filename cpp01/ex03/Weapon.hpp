/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:26:30 by julien            #+#    #+#             */
/*   Updated: 2025/05/31 09:47:24 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class	Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);
		Weapon(Weapon const &src);
		virtual	~Weapon(void);
		
		Weapon				&operator=(Weapon const &rhs);

		std::string const	&getType(void) const;
		void				setType(std::string type);

	private:
		std::string	_type;
};

std::ostream	&operator<<(std::ostream &o, Weapon const &weapon);

#endif
