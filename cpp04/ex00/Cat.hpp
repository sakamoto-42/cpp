/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:43:21 by julien            #+#    #+#             */
/*   Updated: 2025/06/30 08:59:03 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(Cat const &src);
        virtual ~Cat(void);

        Cat             &operator=(Cat const &rhs);

        virtual void    makeSound(void) const;
};

std::ostream    &operator<<(std::ostream &o, Cat const &cat);

#endif
