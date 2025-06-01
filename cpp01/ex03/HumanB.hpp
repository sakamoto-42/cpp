/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:31:34 by julien            #+#    #+#             */
/*   Updated: 2025/06/01 18:53:28 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(void);
		HumanB(std::string name);
		HumanB(HumanB const &src);
		virtual	~HumanB(void);

		HumanB	&operator=(HumanB const &rhs);

		std::string	const	getName(void) const;
		Weapon	const		*getWeapon(void) const;
		void				setWeapon(Weapon &weapon);
		void				attack(void) const;

	private:
		std::string	_name;
		Weapon		*_weapon;
};

std::ostream	&operator<<(std::ostream &o, HumanB const &humanB);

#endif
