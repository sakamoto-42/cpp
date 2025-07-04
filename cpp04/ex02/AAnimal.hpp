/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:33:23 by julien            #+#    #+#             */
/*   Updated: 2025/07/04 10:28:59 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class   AAnimal
{
    public:
        AAnimal(void);
        AAnimal(AAnimal const &src);
        virtual                     ~AAnimal(void);

        AAnimal                     &operator=(AAnimal const &rhs);

        virtual void                makeSound(void) const = 0;
        virtual void                learn(const std::string &idea) = 0;
        virtual const std::string   recall(int idea_index) const = 0;

        const std::string           &getType(void) const;

    protected:
        std::string type;
};

std::ostream    &operator<<(std::ostream &o, AAnimal const &animal);

#endif
