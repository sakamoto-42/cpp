/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:18:38 by juduchar          #+#    #+#             */
/*   Updated: 2025/06/13 09:54:33 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(void) : _fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int integer_number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = integer_number << _fractional_bits;
	return ;
}

Fixed::Fixed(const float floating_point_number)
{
	const float	scale_factor = (float)(1 << _fractional_bits);

	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(floating_point_number * scale_factor);
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_fixed_point_value = rhs.getRawBits();
	}
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBitss member function called" << std::endl;
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
