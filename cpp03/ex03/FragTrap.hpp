/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:58:27 by julien            #+#    #+#             */
/*   Updated: 2025/06/27 08:49:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class   FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(FragTrap const &src);
        virtual ~FragTrap(void);

        FragTrap    &operator=(FragTrap const &rhs);

        void        attack(const std::string& target);
        void        highFivesGuys(void);
};

std::ostream    &operator<<(std::ostream &o, FragTrap const &frag_trap);

#endif
