/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:40 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 10:30:01 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>

class   ICharacter
{
    public:
        ICharacter(void);
        ICharacter(ICharacter const &src);
        virtual ~ICharacter(void);

        ICharacter  &operator=(ICharacter const &rhs);
};

std::ostream    &operator<<(std::ostream &o, ICharacter const &i_character);

#endif
