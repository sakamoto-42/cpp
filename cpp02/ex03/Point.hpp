/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:30:51 by julien            #+#    #+#             */
/*   Updated: 2025/06/17 12:59:32 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class   Point
{
    public:
        Point(void);
        Point(const float x, const float y);
        Point(Point const &src);
		virtual ~Point(void);

        Point	&operator=(Point const &rhs);

        Fixed   getx(void) const;
        Fixed   gety(void) const;

    private:
        const Fixed _x;
        const Fixed _y;
};

std::ostream	&operator<<(std::ostream &o, Point const &point);

#endif
