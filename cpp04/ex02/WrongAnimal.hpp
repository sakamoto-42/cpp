/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:49:06 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 17:29:16 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class   WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const &src);
        virtual ~WrongAnimal(void);

        WrongAnimal  &operator=(WrongAnimal const &rhs);

        void    makeSound(void) const;

        const std::string   &getType(void) const;

    protected:
        std::string type;
};

std::ostream    &operator<<(std::ostream &o, WrongAnimal const &wrong_animal);

#endif
