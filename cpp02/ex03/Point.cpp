/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:39:00 by julien            #+#    #+#             */
/*   Updated: 2025/06/17 18:02:34 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : _x(0), _y(0)
{
	return ;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	return ;
}

Point::Point(Point const &src) :_x(src._x), _y(src._y)
{
	return ;
}

Point::~Point(void)
{
	return ;
}

Point	&Point::operator=(Point const &rhs)
{
	if (this != &rhs)
	{

	}
	return (*this);
}

Fixed   Point::getx(void) const
{
	return (this->_x);
}

Fixed   Point::gety(void) const
{
	return (this->_y);
}


std::ostream	&operator<<(std::ostream &o, Point const &point)
{
    o << "x = " << point.getx() << std::endl;
    o << "y = " << point.gety() << std::endl;
	return (o);
}