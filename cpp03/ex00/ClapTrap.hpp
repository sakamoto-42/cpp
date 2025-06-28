/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:09:59 by julien            #+#    #+#             */
/*   Updated: 2025/06/28 13:46:25 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class   ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &src);
        virtual ~ClapTrap(void);

        ClapTrap            &operator=(ClapTrap const &rhs);

        void                attack(const std::string& target);
        void                takeDamage(unsigned int amount);
        void                beRepaired(unsigned int amount);
    
        const std::string   &getName(void) const;
        unsigned int        getHitPoints(void) const;
        unsigned int        getMaxHitPoints(void) const;
        unsigned int        getEnergyPoints(void) const;
        unsigned int        getAttackDamage(void) const;

    private:
        std::string     _name;
        unsigned int    _hit_points;
        unsigned int    _max_hit_points;
        unsigned int    _energy_points;
        unsigned int    _attack_damage;
};

std::ostream    &operator<<(std::ostream &o, ClapTrap const &clap_trap);

#endif
