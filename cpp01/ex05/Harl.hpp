/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:18:23 by julien            #+#    #+#             */
/*   Updated: 2025/06/09 13:57:38 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	public:
		Harl(void);
		Harl(Harl const &src);
		virtual ~Harl(void);

		Harl &operator=(Harl const &rhs);

		void complain(std::string level) const;

	private:
		void _debug(void) const;
		void _info(void) const;
		void _warning(void) const;
		void _error(void) const;

		static const std::string _levels[];
		enum class Level : int {
			DEBUG = 0,
			INFO,
			WARNING,
			ERROR
		};
		static void (Harl::* const _dispatch_table[4])(void) const;
};

std::ostream &operator<<(std::ostream &o, Harl const &harl);

#endif
