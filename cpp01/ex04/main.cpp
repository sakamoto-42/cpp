/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:06:20 by julien            #+#    #+#             */
/*   Updated: 2025/06/08 11:21:26 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	ft_init(int argc, char *argv[], t_data *data)
{
	if (argc != 4)
	{
		std::cout << "Error : Invalid number of arguments" << std::endl;
		std::cout << "Usage : " << argv[0] << " " << "<filename>";
		std::cout << " " << "<s1>" << " " << "<s2>" << std::endl;
		return (0);
	}
	data->filename = argv[1];
	data->s1 = argv[2];
	data->s1_len = data->s1.length();
	data->s2 = argv[3];
	data->s2_len = data->s2.length();
	data->infile_stream.open(data->filename.c_str());
	data->outfile_stream.open((data->filename.append(".replace")).c_str());
	if (!data->infile_stream.is_open())
	{
		std::cout << "Error : Unable to open file \"" << data->filename << "\"";
		std::cout << std::endl;
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data			data;
	bool			first_line;
	std::string		line;
	std::size_t		found;

	if (!ft_init(argc, argv, &data))
		return (1);
	first_line = true;
	while (std::getline(data.infile_stream, line))
	{
		found = line.find(data.s1);
		while (found != std::string::npos)
		{
			line.erase(found, data.s1_len);
			line.insert(found, data.s2);
			found = line.find(data.s1, found + data.s2_len);
		}
		if (!first_line)
			data.outfile_stream << '\n';
		data.outfile_stream << line;
		first_line = false;
	}
	data.infile_stream.close();
	data.outfile_stream.close();
	return (0);
}
