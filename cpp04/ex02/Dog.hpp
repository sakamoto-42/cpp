/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:46:23 by julien            #+#    #+#             */
/*   Updated: 2025/07/02 14:23:56 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog(void);
        Dog(Dog const &src);
        virtual                     ~Dog(void);

        Dog                         &operator=(Dog const &rhs);

        virtual void                makeSound(void) const;
        virtual void                learn(const std::string &idea);
        virtual const std::string   recall(int idea_index) const;

    private:
        Brain   *_brain;
};

std::ostream    &operator<<(std::ostream &o, Dog const &dog);

#endif
