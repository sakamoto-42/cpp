/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:28:05 by julien            #+#    #+#             */
/*   Updated: 2025/06/30 17:57:12 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class   Animal
{
    public:
        Animal(void);
        Animal(Animal const &src);
        virtual ~Animal(void);

        Animal              &operator=(Animal const &rhs);

        virtual void                makeSound(void) const;
        virtual void                learn(const std::string &idea) = 0;
        virtual const std::string   recall(int idea_index) const = 0;

        const std::string   &getType(void) const;

    protected:
        std::string type;
};

std::ostream    &operator<<(std::ostream &o, Animal const &animal);

#endif
