/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:43:21 by julien            #+#    #+#             */
/*   Updated: 2025/07/04 09:40:14 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(Cat const &src);
        virtual                     ~Cat(void);

        Cat                         &operator=(Cat const &rhs);

        virtual void                makeSound(void) const;
        virtual void                learn(const std::string &idea);
        virtual const std::string   recall(int idea_index) const;

    private:
        Brain   *_brain;
};

std::ostream    &operator<<(std::ostream &o, Cat const &cat);

#endif
