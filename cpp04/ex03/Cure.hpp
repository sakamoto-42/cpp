/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:30 by julien            #+#    #+#             */
/*   Updated: 2025/07/01 00:32:07 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>

class   Cure
{
    public:
        Cure(void);
        Cure(Cure const &src);
        virtual ~Cure(void);

        Cure    &operator=(Cure const &rhs);
};

std::ostream    &operator<<(std::ostream &o, Cure const &cure);

#endif
