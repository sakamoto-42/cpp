/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:42:27 by julien            #+#    #+#             */
/*   Updated: 2025/06/18 13:26:21 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point);

std::string print_result(bool is_in_triangle)
{
    if (is_in_triangle == true)
        return ("P est à l'intérieur du triangle ABC");
    else
        return ("P est à l'extérieur du triangle ABC");
}

int main(void) 
{
    std::cout << "--- Sommets du triangle : A(5, 1), B(7, 5), C(10, 2) ---" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Cas 1 : Point à l'intérieur du triangle (résultat attendu : true) ---" << std::endl;
    std::cout << "P(8, 3) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(8, 3))) << std::endl;
    std::cout << "P(7, 3) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(7, 3))) << std::endl;
    std::cout << "P(8.1f, 3.1f) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(8.1f, 3.1f))) << std::endl;
    std::cout << std::endl;
    
    std::cout << "--- Cas 2 : Point sur le bord du triangle (résultat attendu : false)" << std::endl;
    std::cout << "P(6, 3) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(6, 3))) << std::endl;
    std::cout << "P(8.5f, 3.5f) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(8.5f, 3.5f))) << std::endl;
    std::cout << "P(7.5f, 1.5f) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(7.5f, 1.5f))) << std::endl;
    std::cout << std::endl;
    
    std::cout << "--- Cas 3 : Point sur le sommet du triangle (résultat attendu : false)" << std::endl;
    std::cout << "P(5, 1) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(5, 1))) << std::endl;
    std::cout << "P(7, 5) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(7, 5))) << std::endl;
    std::cout << "P(10, 2) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(10, 2))) << std::endl;
    std::cout << std::endl;

    std::cout << "Cas 4 : Point à l'extérieur du triangle (résultat attendu : false) ---" << std::endl;
    std::cout << "P(0, 0) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(0, 0))) << std::endl;
    std::cout << "P(12, 6) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(12, 6))) << std::endl;
    std::cout << "P(8.1, 1.5f) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(8.1f, 1.5f))) << std::endl;
    std::cout << "P(3, -1) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(3, -1))) << std::endl;        // Colinéaire avec AB, mais dehors -> false
    std::cout << "P(8, 7) : " << print_result(bsp(Point(5, 1), Point(7, 5), Point(10, 2), Point(8, 7))) << std::endl;          // Colinéaire avec AB, mais dehors -> false
    std::cout << std::endl;

    std::cout << "--- Sommets du triangle : A(0, 0), B(5, 0), C(10, 0) ---" << std::endl;
    std::cout << std::endl;

    std::cout << "Cas 5 : Triangle colinéaire (résultat attendu : false) ---" << std::endl;
    std::cout << "P(3, 0) : " << print_result(bsp(Point(0, 0), Point(5, 0), Point(10, 0), Point(3, 0))) << std::endl;      // Sur le segment -> true
    std::cout << "P(12, 0) : " << print_result(bsp(Point(0, 0), Point(5, 0), Point(10, 0), Point(12, 0))) << std::endl;     // Sur la ligne, mais hors du segment -> false
    std::cout << "P(-2, 0) : " << print_result(bsp(Point(0, 0), Point(5, 0), Point(10, 0), Point(-2, 0))) << std::endl;     // Sur la ligne, mais hors du segment -> false
    std::cout << "P(4, 1) : " << print_result(bsp(Point(0, 0), Point(5, 0), Point(10, 0), Point(4, 1))) << std::endl;      // En dehors de la ligne -> false
    std::cout << "P(4.2f, 5.6f) : " << print_result(bsp(Point(0, 0), Point(5, 0), Point(10, 0), Point(4.2f, 5.6f))) << std::endl;      // En dehors de la ligne -> false
    std::cout << std::endl;

    return (0);
}
