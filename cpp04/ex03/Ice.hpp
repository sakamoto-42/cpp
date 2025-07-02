/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:32 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 15:43:45 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class   Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const &src);
        virtual             ~Ice(void);

        Ice                 &operator=(Ice const &rhs);

        virtual void        use(ICharacter &target);

        virtual AMateria    *clone() const;
};

std::ostream    &operator<<(std::ostream &o, Ice const &ice);

#endif
