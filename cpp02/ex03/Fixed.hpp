/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:02:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/06/24 08:48:07 by julien           ###   ########.fr       */
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

		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;
		Fixed	operator++(int);
		Fixed	&operator++();
		Fixed	operator--(int);
		Fixed	&operator--();

		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(Fixed const &a, Fixed const &b);
		static const Fixed	&max(Fixed const &a, Fixed const &b);
		

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_fixed_point_value;
		static const int 	_fractional_bits;	
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
