/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:18:38 by juduchar          #+#    #+#             */
/*   Updated: 2025/06/18 19:54:44 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(void) : _fixed_point_value(0)
{
	return ;
}

Fixed::Fixed(const int integer_number)
{
	this->_fixed_point_value = integer_number << _fractional_bits;
	return ;
}

Fixed::Fixed(const float floating_point_number)
{
	const float	scale_factor = (float)(1 << _fractional_bits);

	this->_fixed_point_value = roundf(floating_point_number * scale_factor);
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
	{
		this->_fixed_point_value = rhs.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->_fixed_point_value > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->_fixed_point_value < rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_fixed_point_value <= rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_fixed_point_value >= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->_fixed_point_value == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_fixed_point_value != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	result;

	result.setRawBits(this->_fixed_point_value + rhs.getRawBits());
	return(result);
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	result;

	result.setRawBits(this->_fixed_point_value - rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	long long	tmp;
	Fixed		result;

	tmp = (long long)this->_fixed_point_value * (long long)rhs.getRawBits();
	result.setRawBits(tmp >> _fractional_bits);
	return (result);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	long long	tmp;
	Fixed		result;

	tmp = (long long)this->_fixed_point_value << _fractional_bits;
	result.setRawBits(tmp / rhs.getRawBits());
	return (result);
}

Fixed	&Fixed::operator++()
{
	this->_fixed_point_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	this->_fixed_point_value++;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->_fixed_point_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	this->_fixed_point_value--;
	return (tmp);
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a >= b)
		return (a);
	return (b);
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point_value = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	const float	scale_factor = (float)(1 << _fractional_bits);

	return (this->_fixed_point_value / scale_factor);
}

int		Fixed::toInt(void) const
{
	return (this->_fixed_point_value >> _fractional_bits);	
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
