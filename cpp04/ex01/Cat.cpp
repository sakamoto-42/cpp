/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:50:44 by julien            #+#    #+#             */
/*   Updated: 2025/06/30 20:49:11 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    this->_brain = new Brain();
    this->type = "Cat";
    std::cout << "Cat default constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Cat::Cat(Cat const &src) : Animal(src), _brain(new Brain(*(src._brain)))
{
    this->type = "Cat";
    std::cout << "Cat copy constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    *this = src;
    return ;
}

Cat::~Cat(void)
{
    delete(this->_brain);
    std::cout << "Cat destructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Cat  &Cat::operator=(Cat const &rhs)
{
    std::cout << "Cat copy assignment operator called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete (this->_brain);
        this->_brain = new Brain(*(rhs._brain));
    }
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "\"Meow !\"" << std::endl;
	return ;
}

void    Cat::learn(const std::string &idea)
{
    this->_brain->addIdea(idea);
    return ;
}

const std::string   Cat::recall(int idea_index) const
{
    return (this->_brain->getIdea(idea_index));
}

std::ostream    &operator<<(std::ostream &o, Cat const &cat)
{
    o << static_cast<const Animal&>(cat);
    return (o);
}
