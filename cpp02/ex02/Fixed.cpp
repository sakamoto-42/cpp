/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:18:38 by juduchar          #+#    #+#             */
/*   Updated: 2025/06/13 11:58:39 by juduchar         ###   ########.fr       */
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

bool	Fixed::operator>(Fixed const &rhs)
{
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<(Fixed const &rhs)
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator<=(Fixed const &rhs)
{
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator>=(Fixed const &rhs)
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator==(Fixed const &rhs)
{
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(Fixed const &rhs)
{
	return (this->toFloat() != rhs.toFloat());
}

float	Fixed::operator+(Fixed const &rhs)
{
	return(this->toFloat() + rhs.toFloat());
}

float	Fixed::operator-(Fixed const &rhs)
{
	return (this->toFloat() - rhs.toFloat());
}

float	Fixed::operator*(Fixed const &rhs)
{
	return (this->toFloat() * rhs.toFloat());
}

float	Fixed::operator/(Fixed const &rhs)
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_fixed_point_value++;
	return (*this);
}

Fixed	Fixed::operator++(int fixed_point_number)
{
	++this->_fixed_point_value;
	return (fixed_point_number);
}

Fixed	Fixed::operator--()
{
	this->_fixed_point_value--;
	return (*this);
}

Fixed	Fixed::operator--(int fixed_point_number)
{
	--this->_fixed_point_value;
	return (fixed_point_number);
}

Fixed		&min(Fixed &fixed_point_number_a, Fixed &fixed_point_number_b)
{
	if (fixed_point_number_a <= fixed_point_number_b)
		return (fixed_point_number_a);
	return (fixed_point_number_b);
}

Fixed		&max(Fixed &fixed_point_number_a, Fixed &fixed_point_number_b)
{
	if (fixed_point_number_a >= fixed_point_number_b)
		return (fixed_point_number_a);
	return (fixed_point_number_b);
}

const Fixed	&min(Fixed const &fixed_point_number_a, Fixed const &fixed_point_number_b)
{
	if (&fixed_point_number_a <= &fixed_point_number_b)
		return (fixed_point_number_a);
	return (fixed_point_number_b);
}

const Fixed	&max(Fixed const &fixed_point_number_a, Fixed const &fixed_point_number_b)
{
	if (&fixed_point_number_a >= &fixed_point_number_b)
		return (fixed_point_number_a);
	return (fixed_point_number_b);
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixed_point_value);
}

void	Fixed::setRawBit(int const raw)
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
