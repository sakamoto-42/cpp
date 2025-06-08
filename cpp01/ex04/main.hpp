/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 09:48:01 by juduchar          #+#    #+#             */
/*   Updated: 2025/06/08 11:06:43 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <fstream>
# include <iostream>
# include <string>

typedef struct s_data
{
	std::string		filename;
	std::string		s1;
	size_t			s1_len;
	std::string		s2;
	size_t			s2_len;
	std::ifstream	infile_stream;
	std::ofstream	outfile_stream;
}	t_data;

#endif