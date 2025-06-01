/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:31:34 by julien            #+#    #+#             */
/*   Updated: 2025/06/01 16:53:47 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>

class	HumanB
{
	public:
		HumanB(void);
		HumanB(std::string name);
		HumanB(HumanB const &src);
		virtual	~HumanB(void);

		HumanB	&operator=(HumanB const &rhs);

		std::string	const	getName(void) const;

	private:
		std::string	_name;
};

std::ostream	&operator<<(std::ostream &o, HumanB const &humanB);

#endif
