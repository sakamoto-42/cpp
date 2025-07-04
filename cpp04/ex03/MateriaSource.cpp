/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:08:18 by julien            #+#    #+#             */
/*   Updated: 2025/07/03 15:26:08 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    this->_initTemplates();
    return ;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    this->_copyTemplates(src);
    return ;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor called" << std::endl;
    this->_deleteTemplates();
    return ;
}

MateriaSource    &MateriaSource::operator=(MateriaSource const &rhs)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_deleteTemplates();
        this->_copyTemplates(rhs);
    }
    return (*this);
}

void            MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return ;
    int i = 0;
    while (i < 4)
    {
        if (!this->_templates[i])
        {
            std::cout << "Learn " << m->getType() << " in slot " << i << std::endl;
            this->_templates[i] = m->clone();
            return ;
        }
        i++;
    }
    return ;
}

AMateria        *MateriaSource::createMateria(std::string const &type)
{
    int i = 0;

    while (i < 4)
    {
        if (this->_templates[i])
        {
            if (this->_templates[i]->getType() == type)
            {
                std::cout << "Create " << type << " in slot " << i << std::endl;
                return (this->_templates[i]->clone());
            }
        }
        i++;
    }
    return (0);
}


void                MateriaSource::printTemplates(std::ostream &o) const
{
    int i = 0;
    while (i < 4)
    {
        o << "\tTemplate " << i << ": ";
        if (this->_templates[i])
        {
            o << this->_templates[i]->getType() << std::endl;
        }
        else
        {
            o << "empty" << std::endl;
        }
        i++;
    }
}

void                MateriaSource::_initTemplates(void)
{
    int i = 0;
    while (i < 4)
    {
        this->_templates[i] = 0;
        i++;
    }
    return ;
}

void                MateriaSource::_copyTemplates(MateriaSource const &src)
{
    int i = 0;

    while (i < 4)
    {
        if (src._templates[i])
        {
            this->_templates[i] = src._templates[i]->clone();
        }
        else
        {
            this->_templates[i] = 0;
        }
        i++;
    }
    return ;
}

void                MateriaSource::_deleteTemplates(void)
{
    int i = 0;

    while (i < 4)
    {
        if (this->_templates[i])
            delete(this->_templates[i]);
        i++;
    }
    return ;
}

std::ostream    &operator<<(std::ostream &o, MateriaSource const &materia_source)
{
    o << "Materia Source :" << std::endl;
    o << "Templates :" << std::endl;
    materia_source.printTemplates(o);
    return (o);
}
