/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:30 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 15:06:50 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class   Cure : public AMateria
{
    public:
        Cure(void);
        Cure(Cure const &src);
        virtual             ~Cure(void);

        Cure                &operator=(Cure const &rhs);

        virtual void        use(ICharacter &target);

        virtual AMateria    *clone(void) const;
};

std::ostream    &operator<<(std::ostream &o, Cure const &cure);

#endif
