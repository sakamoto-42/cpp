/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:19 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 15:00:43 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class   AMateria
{
    public:
        AMateria(void);
        AMateria(std::string const &type);
        AMateria(AMateria const &src);
        virtual             ~AMateria(void);

        AMateria            &operator=(AMateria const &rhs);

        virtual void        use(ICharacter &target);

        std::string const   &getType() const; //Returns the materia type

        virtual AMateria    *clone() const = 0;

    protected:
        std::string _type;
};

#endif
