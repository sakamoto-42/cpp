/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:45 by julien            #+#    #+#             */
/*   Updated: 2025/07/03 14:06:37 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class   IMateriaSource
{
    public:
        virtual             ~IMateriaSource() {}
        virtual void        learnMateria(AMateria *) = 0;
        virtual AMateria    *createMateria(std::string const &type) = 0;
};

#endif
