/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:40:32 by julien            #+#    #+#             */
/*   Updated: 2025/06/18 13:21:11 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"
#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed   dp;
    Fixed   alpha;
    Fixed   beta;
    Fixed   gamma;

    dp = (a.getx() - c.getx()) * (b.gety() - c.gety())
        - (a.gety() - c.gety()) * (b.getx() - c.getx());
    if (dp == Fixed(0))
        return (false);
    alpha = ((point.getx() - c.getx()) * (b.gety() - c.gety())
        - (point.gety() - c.gety()) * (b.getx() - c.getx())
    ) / dp;
    beta = ((a.getx() - c.getx()) * (point.gety() - c.gety())
        - (a.gety() - c.gety()) * (point.getx() - c.getx())
    ) / dp;
    gamma = Fixed(1) - alpha - beta;
    return (alpha > Fixed(0) && beta > Fixed(0) && gamma > Fixed(0));
}
