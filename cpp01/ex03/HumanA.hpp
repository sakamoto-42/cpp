/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:29:27 by julien            #+#    #+#             */
/*   Updated: 2025/06/01 18:42:03 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		HumanA(HumanA const &src);
		virtual	~HumanA(void);

		HumanA	&operator=(HumanA const &rhs);

		std::string	const	getName(void) const;
		Weapon	const		&getWeapon(void) const;
		void				attack(void) const;

	private:
		HumanA(void);
		std::string	_name;
		Weapon		&_weapon;
};

std::ostream	&operator<<(std::ostream &o, HumanA const &humanA);

#endif
