/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:03:51 by julien            #+#    #+#             */
/*   Updated: 2025/07/03 14:27:15 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class   MateriaSource : public IMateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &src);
        virtual             ~MateriaSource(void);

        MateriaSource       &operator=(MateriaSource const &rhs);

        virtual void        learnMateria(AMateria *m);
        virtual AMateria    *createMateria(std::string const &type);

        void                printTemplates(std::ostream &o) const;

    private:
        AMateria            *_templates[4];

        void    _initTemplates(void);
        void    _copyTemplates(MateriaSource const &src);
        void    _deleteTemplates(void);
};

std::ostream    &operator<<(std::ostream &o, MateriaSource const &materia_source);

#endif
