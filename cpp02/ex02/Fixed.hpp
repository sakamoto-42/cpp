/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:02:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/06/13 11:54:39 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const int integer_number);
		Fixed(const float floating_point_number);
		Fixed(Fixed const &src);
		virtual ~Fixed(void);

		Fixed	&operator=(Fixed const &rhs);

		bool	operator>(Fixed const &rhs);
		bool	operator<(Fixed const &rhs);
		bool	operator<=(Fixed const &rhs);
		bool	operator>=(Fixed const &rhs);
		bool	operator==(Fixed const &rhs);
		bool	operator!=(Fixed const &rhs);
		float	operator+(Fixed const &rhs);
		float	operator-(Fixed const &rhs);
		float	operator*(Fixed const &rhs);
		float	operator/(Fixed const &rhs);
		Fixed	operator++(int fixed_point_number);
		Fixed	operator++();
		Fixed	operator--(int fixed_point_number);
		Fixed	operator--();
		

		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed		&min(Fixed &fixed_point_number_a, Fixed &fixed_point_number_b);
		static Fixed		&max(Fixed &fixed_point_number_a, Fixed &fixed_point_number_b);
		static const Fixed	&min(Fixed const &fixed_point_number_a, Fixed const &fixed_point_number_b);
		static const Fixed	&max(Fixed const &fixed_point_number_a, Fixed const &fixed_point_number_b);
		

		int		getRawBits(void) const;
		void	setRawBit(int const raw);

	private:
		int					_fixed_point_value;
		static const int 	_fractional_bits;	
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
