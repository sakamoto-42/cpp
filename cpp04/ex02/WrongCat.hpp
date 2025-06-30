/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:50:12 by julien            #+#    #+#             */
/*   Updated: 2025/06/29 17:13:05 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(WrongCat const &src);
        virtual ~WrongCat(void);

        WrongCat &operator=(WrongCat const &rhs);

        void    makeSound(void) const;
};

std::ostream    &operator<<(std::ostream &o, WrongCat const &wrong_cat);

#endif
