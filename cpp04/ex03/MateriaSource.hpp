/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:03:51 by julien            #+#    #+#             */
/*   Updated: 2025/07/01 01:08:03 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class   MateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &src);
        virtual             ~MateriaSource(void);

        MateriaSource       &operator=(MateriaSource const &rhs);

        virtual void        learnMateria(AMateria *);
        virtual AMateria    *createMateria(std::string const &type);
};

std::ostream    &operator<<(std::ostream &o, MateriaSource const &materia_source);

#endif