/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:09:59 by julien            #+#    #+#             */
/*   Updated: 2025/06/23 12:25:11 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class   ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(ClapTrap const &src);
        virtual ~ClapTrap(void);

        ClapTrap    &operator=(ClapTrap const &rhs);
};

std::ostream    &operator<<(std::ostream &o, ClapTrap const &clap_trap);

#endif