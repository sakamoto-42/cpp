/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:08:18 by julien            #+#    #+#             */
/*   Updated: 2025/07/01 01:13:32 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    return ;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = src;
    return ;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor called" << std::endl;
    return ;
}

MateriaSource    &MateriaSource::operator=(MateriaSource const &rhs)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

void            MateriaSource::learnMateria(AMateria *)
{
    return ;
}

AMateria        *MateriaSource::createMateria(std::string const &type)
{
    return ;
}

std::ostream    &operator<<(std::ostream &o, MateriaSource const &materia_source)
{
    (void)materia_source;
    o << "Materia Source" << std::endl;
    return (o);
}
