/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:31:39 by juduchar          #+#    #+#             */
/*   Updated: 2025/06/18 13:30:02 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

int main(void) {
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

    std::cout << "--- MY TESTS BEGIN ---" << std::endl;
    
    std::cout << "--- MY TESTS END ---" << std::endl;
    return (0);
}
