/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:41:42 by julien            #+#    #+#             */
/*   Updated: 2025/06/25 14:43:14 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &src);
        virtual ~ScavTrap(void);

        ScavTrap        &operator=(ScavTrap const &rhs);

        void            attack(const std::string& target);
        void            guardGate(void);
};

std::ostream    &operator<<(std::ostream &o, ScavTrap const &scav_trap);

#endif
