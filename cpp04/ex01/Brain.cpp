/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:56:29 by julien            #+#    #+#             */
/*   Updated: 2025/06/30 17:54:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain(void) : _ideas_next_index(0)
{
    std::cout << "Brain default constructor called" << std::endl;
    return ;
}

Brain::Brain(Brain const &src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
    return ;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

Brain  &Brain::operator=(Brain const &rhs)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return (*this);
}

void    Brain::addIdea(const std::string &idea)
{
    if (this->_ideas_next_index >= 100)
        return ;
    this->_ideas[this->_ideas_next_index] = idea;
    this->_ideas_next_index++;
}

const std::string   Brain::getIdea(int idea_index) const
{
    if (idea_index >= 0 && idea_index < _ideas_next_index) {
        return (_ideas[idea_index]);
    }
    return ("");
}

/*
std::ostream    &operator<<(std::ostream &o, Brain const &brain)
{
    o << "Brain" << std::endl;
    return (o);
}
*/