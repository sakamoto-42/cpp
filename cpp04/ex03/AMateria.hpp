/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:19 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 10:25:01 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class   AMateria
{
    public:
        AMateria(void);
        AMateria(AMateria const &src);
        virtual ~AMateria(void);

        AMateria  &operator=(AMateria const &rhs);
};

std::ostream    &operator<<(std::ostream &o, AMateria const &a_materia);

#endif
