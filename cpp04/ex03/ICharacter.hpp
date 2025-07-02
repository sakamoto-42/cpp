/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:40 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 16:08:26 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>

class   AMateria;

class   ICharacter
{
    public:
        virtual                     ~ICharacter(void) {}
        virtual std::string const   &getName() const = 0;
        virtual void                equip(AMateria *m) = 0;
        virtual void                unequip(int idx) = 0;
        virtual void                use(int idx, ICharacter &target) = 0;
};

#endif
