/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:31:39 by juduchar          #+#    #+#             */
/*   Updated: 2025/06/22 17:00:16 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

int main(void) {
    {
        Fixed   a;
        Fixed   const b(Fixed(5.05f) * Fixed(2));

        std::cout << "--- SUBJECT TESTS BEGIN ---" << std::endl;
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max(a, b) << std::endl;
        std::cout << "--- SUBJECT TESTS END ---" << std::endl;
        std::cout << std::endl;
    }
    std::cout << "--- MY TESTS BEGIN ---" << std::endl;
    std::cout << std::endl;
    {
        std::cout << "--- Comparison operators ---" << std::endl;
        std::cout << std::endl;

        Fixed a(10.5f);
        Fixed b(20.5f);
        Fixed c(10.5f);
        
        std::cout << std::boolalpha;

        std::cout << "Test > operator :" << std::endl;
        std::cout << "b(20.5f) > a(10.5f)  : " << (b > a) << " (résultat attendu : true)" << std::endl;
        std::cout << "a(10.5f) > b(20.5f)  : " << (a > b) << " (résultat attendu : false)" << std::endl;
        std::cout << "a(10.5f) > c(10.5f)  : " << (a > c) << " (résultat attendu : false)" << std::endl;
        std::cout << std::endl;

        std::cout << "Test < operator :" << std::endl;
        std::cout << "a(10.5f) < b(20.5f)  : " << (a < b) << " (résultat attendu: true)" << std::endl;
        std::cout << "b(20.5f) < a(10.5f)  : " << (b < a) << " (résultat attendu: false)" << std::endl;
        std::cout << "a(10.5f) < c(10.5f)  : " << (a < c) << " (résultat attendu: false)" << std::endl;
        std::cout << std::endl;

        std::cout << "Test <= operator :" << std::endl;
        std::cout << "a(10.5f) <= b(20.5f) : " << (a <= b) << " (résultat attendu: true)" << std::endl;
        std::cout << "a(10.5f) <= c(10.5f) : " << (a <= c) << " (résultat attendu: true)" << std::endl;
        std::cout << "b(20.5f) <= a(10.5f) : " << (b <= a) << " (résultat attendu: false)" << std::endl;
        std::cout << std::endl;

        std::cout << "Test >= operator :" << std::endl;
        std::cout << "b(20.5f) >= a(10.5f) : " << (b >= a) << " (résultat attendu : true)" << std::endl;
        std::cout << "a(10.5f) >= c(10.5f) : " << (a >= c) << " (résultat attendu : true)" << std::endl;
        std::cout << "a(10.5f) >= b(10.5f) : " << (a >= b) << " (résultat attendu : false)" << std::endl;
        std::cout << std::endl;

        std::cout << "Test == operator :" << std::endl;
        std::cout << "a(10.5f) == c(10.5f) : " << (a == c) << " (résultat attendu : true)" << std::endl;
        std::cout << "a(10.5f) == b(20.5f) : " << (a == b) << " (résultat attendu : false)" << std::endl;
        std::cout << std::endl;

        std::cout << "Test != operator :" << std::endl;
        std::cout << "a(10.5f) != b(20.5f) : " << (a != b) << " (résultat attendu : true)" << std::endl;
        std::cout << "a(10.5f) != c(10.5f) : " << (a != c) << " (résultat attendu : false)" << std::endl;
        
        std::cout << std::endl;
        std::cout << std::noboolalpha;
    }
    {
        std::cout << "--- Arithmetic operators ---" << std::endl;
        std::cout << std::endl;

        Fixed   a(8.5f);
        Fixed   b(2.25f);
        Fixed   c(-4.0f);
        Fixed   d(10.75f);

        std::cout << "Test + operator :" << std::endl;
        std::cout << "a(8.5f) + b(2.25f) = " << (a + b) << " (résultat attendu : 10.75)" << std::endl;
        std::cout << "b(2.25f) + c(-4.0f) = " << (b + c) << " (résultat attendu : -1.75)" << std::endl;
        std::cout << "c(-4.0f) + Fixed(4.0f) = " << (c + Fixed(4.0f)) << " (résultat attendu : 0)" << std::endl;
        std::cout << std::endl;

        std::cout << "Test - operator :" << std::endl;
        std::cout << "a(8.5f) - b(2.25f) = " << (a - b) << " (résultat attendu : 6.25)" << std::endl;
        std::cout << "b(2.25f) - a(8.5f) = " << (b - a) << " (résultat attendu : -6.25)" << std::endl;
        std::cout << "a(8.5f) - a(8.5f) = " << (a - a) << " (résultat attendu : 0)" << std::endl;
        std::cout << std::endl;

        std::cout << "Test * operator :" << std::endl;
        std::cout << "a(8.5f) * b(2.25f) = " << (a * b) << " (résultat attendu : 19.125)" << std::endl;
        std::cout << "a * Fixed(-0.5f) = " << (a * Fixed(-0.5f)) << " (résultat attendu : -4.25)" << std::endl;
        std::cout << "a(8.5f) * Fixed(0) = " << (a * Fixed(0)) << " (résultat attendu : 0)" << std::endl;
        std::cout << std::endl;

        std::cout << "Test / operator :" << std::endl;
        std::cout << "a(8.5f) / Fixed(0.5f) = " << (a / Fixed(0.5f)) << " (résultat attendu : 17)" << std::endl;
        std::cout << "a(8.5f) / c(-4.0f) = " << (a / c) << " (résultat attendu : -2.125)" << std::endl;
        std::cout << "d(10.75f) / b(2.25f) = " << (d / b) << " (résultat attendu : 4.77734) " << "/!\\ perte de précision (résultat exact : 4.777777...)" << std::endl;
        //std::cout << "a(8.5f) / Fixed(0) = " << (a / Fixed(0)) << std::endl; // division par 0 => seg fault
        std::cout << std::endl;

        std::cout << "Test linked arithmetic operators :" << std::endl;
        std::cout << "(d(10.75f) - a(8.5f)) + b(2.25f) = " << (d - a) + b << " (résultat attendu : 4.5)" << std::endl;
        std::cout << "(a(8.5f) * c(-4.0f)) / b(2.25f) = " << (a * c) / b << " (résultat attendu : -15.1094) " << "/!\\ perte de précision (résultat exact : -15.111111...)" << std::endl;
        std::cout << "(a(8.5f) + b(2.25f) - Fixed(0.75f)) * c(-4.0f) / Fixed(2.0f) = " << (a + b - Fixed(0.75f)) * c / Fixed(2.0f) << " (résultat attendu : -20) " << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "--- Increment and decrement operators ---" << std::endl;
        std::cout << std::endl;
        Fixed   epsilon;

        epsilon.setRawBits(1);
        std::cout << "Epsilon = " << epsilon << " (résultat attendu : 0.00390625 soit 1/256)" << std::endl;
        {
            std::cout << "Test pre-increment (++i) operator :" << std::endl;
            Fixed   i(10.0f);
            Fixed   i_before_increment = i;
            std::cout << "Valeur avant incrémentation : " << i_before_increment << std::endl;
            Fixed   i_after_increment = ++i;
            std::cout << "Valeur après incrémentation : " << i << std::endl;
            std::cout << "Valeur retournée par ++i : " << i_after_increment << std::endl;

            std::cout << std::boolalpha;
            std::cout << "(i == i_before_increment + epsilon) = " << (i == i_before_increment + epsilon) << " (résultat attendu : true)" << std::endl;
            std::cout << "(i == i_after_increment) = " << (i == i_after_increment) << " (résultat attendu : true)" << std::endl;
            std::cout << std::endl;
            std::cout << std::noboolalpha;
        }
        {
            std::cout << "Test post-increment (i++) operator :" << std::endl;
            Fixed   i(10.0f);
            Fixed   i_before_increment = i;
            std::cout << "Valeur avant incrémentation : " << i_before_increment << std::endl;
            Fixed   i_after_increment = i++;
            std::cout << "Valeur après incrémentation : " << i << std::endl;
            std::cout << "Valeur retournée par i++ : " << i_after_increment << std::endl;

            std::cout << std::boolalpha;
            std::cout << "(i == i_before_increment + epsilon) = " << (i == i_before_increment + epsilon) << " (résultat attendu : true)" << std::endl;
            std::cout << "(i_after_increment == i_before_increment) = " << (i_after_increment == i_before_increment) << " (résultat attendu : true)" << std::endl;
            std::cout << std::endl;
            std::cout << std::noboolalpha;
        }
        {
            std::cout << "Test pre-decrement (--i) operator :" << std::endl;
            Fixed   i(10.0f);
            Fixed   i_before_decrement = i;
            std::cout << "Valeur avant décrémentation : " << i_before_decrement << std::endl;
            Fixed   i_after_decrement = --i;
            std::cout << "Valeur après décrémentation : " << i << std::endl;
            std::cout << "Valeur retournée par --i : " << i_after_decrement << std::endl;

            std::cout << std::boolalpha;
            std::cout << "(i == i_before_decrement - epsilon) = " << (i == i_before_decrement - epsilon) << " (résultat attendu : true)" << std::endl;
            std::cout << "(i == i_after_decrement) = " << (i == i_after_decrement) << " (résultat attendu : true)" << std::endl;
            std::cout << std::endl;
            std::cout << std::noboolalpha;
        }
        {
            std::cout << "Test post-decrement (i--) operator :" << std::endl;
            Fixed   i(10.0f);
            Fixed   i_before_decrement = i;
            std::cout << "Valeur avant décrémentation : " << i_before_decrement << std::endl;
            Fixed   i_after_decrement = i--;
            std::cout << "Valeur après décrémentation : " << i << std::endl;
            std::cout << "Valeur retournée par i-- : " << i_after_decrement << std::endl;

            std::cout << std::boolalpha;
            std::cout << "(i == i_before_decrement - epsilon) = " << (i == i_before_decrement - epsilon) << " (résultat attendu : true)" << std::endl;
            std::cout << "(i_after_decrement == i_before_decrement) = " << (i_after_decrement == i_before_decrement) << " (résultat attendu : true)" << std::endl;
            std::cout << std::endl;
            std::cout << std::noboolalpha;
        }
    }
    {
        std::cout << "--- min and max functions ---" << std::endl;
        std::cout << std::endl;

        Fixed a(100);
        Fixed b(200.5f);
        
        std::cout << "Test static Fixed	&min(Fixed &a, Fixed &b)" << std::endl;
        std::cout << "a = 100 ; b = 200.5f" << std::endl;
        std::cout << "min : a(100)" << std::endl;
        Fixed& min_ref = Fixed::min(a, b);
        std::cout << "Fixed::min(a, b) = " << min_ref << " (résultat attendu : 100)" << std::endl;
        std::cout << std::boolalpha;
        std::cout << "(min_ref == a) = " << (min_ref == a) << " (résultat attendu : true)" << std::endl;
        std::cout << "(&min_ref == &a) = " << (&min_ref == &a) << " (résultat attendu : true)" << std::endl;
        std::cout << std::endl;
        std::cout << std::noboolalpha;
        {
            std::cout << "a = " << a << " (résultat attendu: 100)" << std::endl;
            std::cout << "Fixed::min(a, b) = Fixed(-50)" << std::endl;
            Fixed::min(a, b) = Fixed(-50);
            std::cout << "a = " << a << " (résultat attendu: -50)" << std::endl;
            std::cout << std::endl;
        }

        std::cout << "Test static Fixed	&max(Fixed &a, Fixed &b)" << std::endl;
        std::cout << "a = 100 ; b = 200.5f" << std::endl;
        Fixed& max_ref = Fixed::max(a, b);
        std::cout << "Fixed::max(a, b) = " << max_ref << " (résultat attendu : 200.5)" << std::endl;
        std::cout << std::boolalpha;
        std::cout << "(max_ref == b) = " << (max_ref == b) << " (résultat attendu : true)" << std::endl;
        std::cout << "(&max_ref == &b) = " << (&max_ref == &b) << " (résultat attendu : true)" << std::endl;
        std::cout << std::endl;
        std::cout << std::noboolalpha;
        {
            std::cout << "b = " << b << " (résultat attendu: 200.5f)" << std::endl;
            std::cout << "Fixed::max(a, b) = Fixed(350)" << std::endl;
            Fixed::max(a, b) = Fixed(350);
            std::cout << "b = " << b << " (résultat attendu: 350)" << std::endl;
            std::cout << std::endl;
        }

        const Fixed const_a(100);
        const Fixed const_b(200.5f);

        std::cout << "Test static const Fixed &min(Fixed const &a, Fixed const &b)" << std::endl;
        std::cout << "const_a = 100 ; const_b = 200.5f" << std::endl;
        const Fixed& const_min_ref = Fixed::min(const_a, const_b);
        std::cout << "Fixed::min(const_a, const_b) = " << const_min_ref << " (résultat attendu : 100)" << std::endl;
        std::cout << std::boolalpha;
        std::cout << "(const_min_ref == const_a) = " << (const_min_ref == const_a) << " (résultat attendu : true)" << std::endl;
        std::cout << "(&const_min_ref == &const_a) = " << (&const_min_ref == &const_a) << " (résultat attendu : true)" << std::endl;
        std::cout << std::endl;
        std::cout << std::noboolalpha;
        //Fixed::min(const_a, const_b) = Fixed(0);
        std::cout << "Test static const Fixed &max(Fixed const &a, Fixed const &b)" << std::endl;
        std::cout << "const_a = 100 ; const_b = 200.5f" << std::endl;
        const Fixed& const_max_ref = Fixed::max(const_a, const_b);
        std::cout << "Fixed::max(const_a, const_b) = " << const_max_ref << " (résultat attendu : 200.5)" << std::endl;
        std::cout << std::boolalpha;
        std::cout << "(const_max_ref == const_b) = " << (const_max_ref == const_b) << " (résultat attendu : true)" << std::endl;
        std::cout << "(&const_max_ref == &const_b) = " << (&const_max_ref == &const_b) << " (résultat attendu : true)" << std::endl;
        std::cout << std::endl;
        std::cout << std::noboolalpha;
    }
    std::cout << "--- MY TESTS END ---" << std::endl;
    return (0);
}
