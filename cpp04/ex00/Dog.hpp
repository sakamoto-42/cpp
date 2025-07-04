/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:46:23 by julien            #+#    #+#             */
/*   Updated: 2025/07/04 09:06:13 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(Dog const &src);
        virtual         ~Dog(void);

        Dog             &operator=(Dog const &rhs);

        virtual void    makeSound(void) const;
};

std::ostream    &operator<<(std::ostream &o, Dog const &dog);

#endif
