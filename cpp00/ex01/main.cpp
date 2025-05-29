/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:07:11 by julien            #+#    #+#             */
/*   Updated: 2025/05/28 21:42:46 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	ft_print_instructions(void)
{
	std::cout << "--- Welcome to My Awesome Phonebook ---" << std::endl;
	std::cout << "Please enter one of these commands :" << std::endl;
	std::cout << "\tADD : save a new contact" << std::endl;
	std::cout << "\tSEARCH : display a specific contact" << std::endl;
	std::cout << "\tEXIT : quit (/!\\ the contacts will be lost forever!)";
	std::cout << std::endl;
}

int	main(int argc, char *argv[])
{
	std::string	command;
	PhoneBook	myPhoneBook;

	(void)argc;
	ft_print_instructions();
	while (std::cout << argv[0] << "> " && std::getline(std::cin, command))
	{
		if (command == "ADD")
			myPhoneBook.ft_add_contact();
		else if (command == "SEARCH")
			myPhoneBook.ft_search_contact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	std::cout << "Bye !" << std::endl;
	return (0);
}
