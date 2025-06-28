/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:24:44 by julien            #+#    #+#             */
/*   Updated: 2025/06/28 08:15:28 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &src);
        virtual ~DiamondTrap(void);

        DiamondTrap         &operator=(DiamondTrap const &rhs);
    
        void                attack(const std::string& target);
        void                whoAmI(void) const;

        const std::string   &getName(void) const;
        unsigned int        getHitPoints(void) const;
        unsigned int        getEnergyPoints(void) const;
        unsigned int        getAttackDamage(void) const;

    private:
        std::string _name;
};

std::ostream    &operator<<(std::ostream &o, DiamondTrap const &diamond_trap);

#endif
