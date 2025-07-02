/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:52:39 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 14:04:40 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class   Character : public ICharacter
{
    public:
        Character(void);
        Character(std::string name);
        Character(Character const &src);
        virtual                     ~Character(void);

        Character                   &operator=(Character const &rhs);

        virtual std::string const   &getName() const;
        virtual void                equip(AMateria *m);
        virtual void                unequip(int idx);
        virtual void                use(int idx, ICharacter &target);

    private:
        std::string _name;
};

std::ostream    &operator<<(std::ostream &o, Character const &character);

#endif
