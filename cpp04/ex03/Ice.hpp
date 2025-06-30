/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:11:32 by julien            #+#    #+#             */
/*   Updated: 2025/07/01 00:32:02 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>

class   Ice
{
    public:
        Ice(void);
        Ice(Ice const &src);
        virtual ~Ice(void);

        Ice     &operator=(Ice const &rhs);
};

std::ostream    &operator<<(std::ostream &o, Ice const &ice);

#endif
