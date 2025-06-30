/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:51:24 by julien            #+#    #+#             */
/*   Updated: 2025/06/30 18:13:23 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->_brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog default constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Dog::Dog(Dog const &src) : Animal(src), _brain(new Brain(*(src._brain)))
{
    this->type = "Dog";
    std::cout << "Dog copy constructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Dog::~Dog(void)
{
    delete(this->_brain);
    std::cout << "Dog destructor called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    return ;
}

Dog  &Dog::operator=(Dog const &rhs)
{
    std::cout << "Dog copy assignment operator called with :" << std::endl;
    std::cout << "Type : " << this->getType() << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete (this->_brain);
        this->_brain = new Brain(*(rhs._brain));
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "\"Waf !\"" << std::endl;
	return ;
}

void    Dog::learn(const std::string &idea)
{
    this->_brain->addIdea(idea);
    return ;
}

const std::string   Dog::recall(int idea_index) const
{
    return (this->_brain->getIdea(idea_index));
}

std::ostream    &operator<<(std::ostream &o, Dog const &dog)
{
    o << static_cast<const Animal&>(dog);
    return (o);
}
