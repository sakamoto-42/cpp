/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:45 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 10:31:04 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>

class   IMateriaSource
{
    public:
        IMateriaSource(void);
        IMateriaSource(IMateriaSource const &src);
        virtual ~IMateriaSource(void);

        IMateriaSource  &operator=(IMateriaSource const &rhs);
};

std::ostream    &operator<<(std::ostream &o, IMateriaSource const &i_materia_source);

#endif
