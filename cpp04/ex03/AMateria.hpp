/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:19 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 16:17:38 by julien           ###   ########.fr       */
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

        std::string const   &getType(void) const;

        virtual AMateria    *clone(void) const = 0;

    protected:
        const std::string _type;
};

#endif
