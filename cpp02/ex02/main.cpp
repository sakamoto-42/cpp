/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:31:39 by juduchar          #+#    #+#             */
/*   Updated: 2025/06/18 20:02:46 by julien           ###   ########.fr       */
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
        std::cout << "--- Comparison operators --" << std::endl;
        std::cout << std::endl;

        Fixed a(10.5f);
        Fixed b(20.5f);
        Fixed c(10.5f);
        
        std::cout << std::boolalpha;

        std::cout << "testing > operator : " << std::endl;
        std::cout << "b(10.5) > a(20.5)  : " << (b > a) << " (résultat attendu : true)" << std::endl;
        std::cout << "a(10.5) > b(20.5)  : " << (a > b) << " (résultat attendu : false)" << std::endl;
        std::cout << "a(10.5) > c(20.5)  : " << (a > c) << " (résultat attendu : false)" << std::endl;
        std::cout << std::endl;

        std::cout << "testing < operator : " << std::endl;
        std::cout << "a(10.5) < b(20.5)  : " << (a < b) << " (résultat attendu: true)" << std::endl;
        std::cout << "b(10.5) < a(20.5)  : " << (b < a) << " (résultat attendu: false)" << std::endl;
        std::cout << "a(10.5) < c(20.5)  : " << (a < c) << " (résultat attendu: false)" << std::endl;
        std::cout << std::endl;

        std::cout << "testing <= operator : " << std::endl;
        std::cout << "a(10.5) <= b(10.5) : " << (a <= b) << " (résultat attendu: true)" << std::endl;
        std::cout << "a(10.5) <= c(10.5) : " << (a <= c) << " (résultat attendu: true)" << std::endl;
        std::cout << "b(10.5) <= a(10.5) : " << (b <= a) << " (résultat attendu: false)" << std::endl;
        std::cout << std::endl;

        std::cout << "testing >= operator : " << std::endl;
        std::cout << "b(10.5) >= a(10.5) : " << (b >= a) << " (résultat attendu : true)" << std::endl;
        std::cout << "a(10.5) >= c(10.5) : " << (a >= c) << " (résultat attendu : true)" << std::endl;
        std::cout << "a(10.5) >= b(10.5) : " << (a >= b) << " (résultat attendu : false)" << std::endl;
        std::cout << std::endl;

        std::cout << "testing == operator : " << std::endl;
        std::cout << "a(10.5) == c(10.5) : " << (a == c) << " (résultat attendu : true)" << std::endl;
        std::cout << "a(10.5) == b(10.5) : " << (a == b) << " (résultat attendu : false)" << std::endl;
        std::cout << std::endl;

        std::cout << "testing != operator : " << std::endl;
        std::cout << "a(10.5) != b(20.5) : " << (a != b) << " (résultat attendu : true)" << std::endl;
        std::cout << "a(10.5) != c(20.5) : " << (a != c) << " (résultat attendu : false)" << std::endl;
        
        std::cout << std::endl;
        std::cout << std::noboolalpha;
    }
    std::cout << "--- MY TESTS END ---" << std::endl;
    return (0);
}
