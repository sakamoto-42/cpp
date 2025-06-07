/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:06:20 by julien            #+#    #+#             */
/*   Updated: 2025/06/01 21:50:06 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::ifstream	infile_stream;

	if (argc != 4)
	{
		std::cout << "Error : Invalid number of arguments" << std::endl;
		std::cout << "Usage : " << argv[0] << " " << "<filename>";
		std::cout << " " << "<s1>" << " " << "<s2>" << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	infile_stream.open(filename.c_str());
	if (!infile_stream.is_open())
	{
		std::cout << "Error : Unable to open file \"" << filename << "\"";
		std::cout << std::endl;
		return (1);
	}
	// .......
	infile_stream.close();
	return (0);
	/*
	std::string	line;

	while (std::getline(infile_stream, line))
		std::cout << line << std::endl;
	infile_stream.close();
	*/
	/*
	std::ofstream			outfile_stream;

	outfile_stream.open("outfile");
	if (!outfile_stream.is_open())
	{
		std::cout << "Error : Unable to open outfile" << std::endl;
		return (1);
	}
	std::cout << "outfile opened !";
	outfile_stream << "Test";
	outfile_stream.close();

	std::ifstream		infile_stream;

	infile_stream.open("infile");
	if (!infile_stream.is_open())
	{
		std::cout << "Error : Unable to open infile" << std::endl;
		return (1);
	}
	std::cout << "infile opened !";
	std::cout << std::endl;
	std::string	word;
	while (infile_stream >> word)
		std::cout << word << std::endl;
	infile_stream.close();

	infile_stream.open("infile");
	if (!infile_stream.is_open())
	{
		std::cout << "Error : Unable to open infile" << std::endl;
		return (1);
	}
	std::cout << "infile opened !";
	std::cout << std::endl;
	*/
	//return (0);	
}