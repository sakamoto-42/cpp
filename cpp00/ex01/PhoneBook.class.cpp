/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:08:22 by julien            #+#    #+#             */
/*   Updated: 2025/05/28 10:23:23 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(void) : _contact_count(0), _next_contact_index(0)
{
	return ;
}

PhoneBook::PhoneBook(PhoneBook const &src)
{
	*this = src;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

PhoneBook	&PhoneBook::operator=(PhoneBook const &rhs)
{
	int	i;

	if (this != &rhs)
	{
		this->_contact_count = rhs._contact_count;
		this->_next_contact_index = rhs._next_contact_index;
		i = 0;
		while (i < 8)
		{
			this->_contacts[i] = rhs._contacts[i];
			i++;
		}
	}
	return (*this);
}

void	PhoneBook::ft_add_contact(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	this->_ft_print_add_contact_warning();
	if (!(PhoneBook::_ft_get_contact_fields(first_name, last_name, nickname,
		phone_number, darkest_secret)))
	{
		return ;
	}
	Contact	new_contact(first_name, last_name,
		nickname, phone_number, darkest_secret);
	this->_ft_save_contact(new_contact);
	return ;
}

void	PhoneBook::ft_search_contact(void) const
{
	std::string	index_input;
	int			index;

	this->_ft_display_summary_contacts();
	if (this->_contact_count == 0)
		return ;
	while (true)
	{
		std::cout << "Enter the index of the contact to display :" << std::endl;
		if (!std::getline(std::cin, index_input))
			return ;
		if (!ft_is_numeric(index_input))
		{
			std::cout << "Error : invalid index" << std::endl;
			continue ;
		}
		index = std::atoi(index_input.c_str());
		if (index >= 1 && index <= this->get_contact_count())
			break ;
		std::cout << "Error : index " << index;
		std::cout << " is invalid" << std::endl;
	}
	std::cout << this->_contacts[index - 1];
	return ;
}

int		PhoneBook::get_contact_count(void) const
{
	return (this->_contact_count);
}

const Contact	&PhoneBook::get_contact(int index) const
{
	return (this->_contacts[index]);
}

void		PhoneBook::_ft_print_add_contact_warning(void) const
{
	if (this->_contact_count < 8)
	{
		std::cout << "/!\\ This phoneBook can store a maximum of ";
		std::cout << "8 contacts" << std::endl;
		std::cout << "You are about to add contact number ";
		std::cout << this->_contact_count + 1 << std::endl;
	}
	else
	{
		std::cout << "/!\\ This phoneBook is full (8 contacts stored)";
		std::cout << std::endl;
		std::cout << "/!\\ Adding a new contact will replace the oldest one ";
		std::cout << "(contact number " << this->_next_contact_index + 1 << ")";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool	PhoneBook::_ft_get_contact_field(
	const std::string &field,
	std::string &input
)
{
	while (true)
	{
		std::cout << field << " :" << std::endl;
		std::cout << "> ";
		if (!std::getline(std::cin, input))
			return (false);
		if (!input.empty())
			return (true);
		std::cout << "Error : " << field << " cannot be empty" << std::endl;
	}
}

bool	PhoneBook::_ft_get_contact_fields(
			std::string &first_name,
			std::string &last_name,
			std::string &nickname,
			std::string &phone_number,
			std::string &darkest_secret
		)
{
	if (!PhoneBook::_ft_get_contact_field("First name", first_name))
		return (false);
	if (!PhoneBook::_ft_get_contact_field("Last name", last_name))
		return (false);
	if (!PhoneBook::_ft_get_contact_field("Nickname", nickname))
		return (false);
	if (!PhoneBook::_ft_get_contact_field("Phone number", phone_number))
		return (false);
	if (!PhoneBook::_ft_get_contact_field("Darkest secret", darkest_secret))
		return (false);
	return (true);
}

void PhoneBook::_ft_save_contact(const Contact &new_contact)
{
	this->_contacts[this->_next_contact_index] = new_contact;
    if (this->_contact_count < 8)
	{
        this->_contact_count++;
	}
	std::cout << "Contact " << this->_next_contact_index + 1 << " added !";
	std::cout << std::endl;
	this->_next_contact_index = (this->_next_contact_index + 1) % 8;
}

void	PhoneBook::_ft_display_summary_contacts(void) const
{
	int	i;

	if (this->_contact_count == 0)
	{
		std::cout << "The phonebook is empty" << std::endl;	
		return ;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	i = 0;
	while (i < this->_contact_count)
	{
		this->_contacts[i].ft_display_summary(i + 1);
		i++;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &o, PhoneBook const &phonebook)
{
	int	contact_count;
	int	i;

	contact_count = phonebook.get_contact_count();
	if (contact_count == 0)
	{
		o << "The phonebook is empty" << std::endl;
		return (o);
	}
	i = 0;
	while (i < contact_count)
	{
		o << "Contact " << (i + 1) << " :" << std::endl;
		o << phonebook.get_contact(i);
		if (i < contact_count - 1)
			std::cout << std::endl;
		i++;
	}
	return (o);
}
