/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:42:27 by julien            #+#    #+#             */
/*   Updated: 2025/06/16 22:08:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    int xa;
    int ya;
    int xb;
    int yb;
    int xc;
    int yc;
    int xp;
    int yp;
    int g1;
    int g2;
    int g3;
    int g4;
    int d1;
    int d2;
    int dp;
    int dalpha;
    float   alpha;
    int dbeta;
    float   beta;
    float   gamma;

    xa = 5;
    ya = 1;
    xb = 7;
    yb = 5;
    xc = 10;
    yc = 2;
    xp = 9;
    yp = 4;

    g1 = xa - xc;
    g2 = xb - xc;
    g3 = ya - yc;
    g4 = yb - yc;
    d1 = xp - xc;
    d2 = yp - yc;

    dp = g1 * g4 - g2 * g3;

    dalpha = d1 * g4 - g2 * d2;
    alpha = (float)dalpha / dp;

    dbeta = g1 * d2 - d1 * g3;
    beta = (float)dbeta / dp;

    gamma = 1 - alpha - beta;

    if ((alpha >= 0 && beta >= 0 && gamma >= 0)
        // fabs(alpha + beta + gamma - 1.0f) < epsilon
        && ((alpha + beta + gamma) == 1))
        std::cout << "P est à l'intérieur du triangle ABC" << std::endl;
    else if ((alpha == 0 && beta > 0 && gamma > 0)
        || (beta == 0 && alpha > 0 && gamma > 0)
        || (gamma == 0 && alpha > 0 && beta > 0))
        std::cout << "P est sur un des côtés du triangle ABC" << std::endl;
    else
        std::cout << "P est à l'extérieur du triangle ABC" << std::endl;
    return (0);
}