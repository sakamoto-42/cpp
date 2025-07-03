/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:52:39 by julien            #+#    #+#             */
/*   Updated: 2025/07/03 11:08:42 by julien           ###   ########.fr       */
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

        virtual void                equip(AMateria *m);
        virtual void                unequip(int idx);
        virtual void                use(int idx, ICharacter &target);

        virtual std::string const   &getName() const;
        void                        printInventory(std::ostream &o) const;


    private:
        std::string _name;
        AMateria    *_inventory[4];

        void    _initInventory(void);
        void    _copyInventory(Character const &src);
        void    _deleteInventory(void);
};

std::ostream    &operator<<(std::ostream &o, Character const &character);

#endif
