/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:08:19 by julien            #+#    #+#             */
/*   Updated: 2025/05/28 09:34:18 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.class.hpp"

Contact::Contact(void) :
	_first_name(""),
	_last_name(""),
	_nickname(""),
	_phone_number(""),
	_darkest_secret("")
{
	return ;
}

Contact::Contact(
			const std::string &first_name,
			const std::string &last_name,
			const std::string &nickname,
			const std::string &phone_number,
			const std::string &darkest_secret
		) : _first_name(first_name),
			_last_name(last_name),
			_nickname(nickname),
			_phone_number(phone_number),
			_darkest_secret(darkest_secret)
{
	return ;
}

Contact::Contact(Contact const &src)
{
	*this = src;
	return ;
}

Contact::~Contact(void)
{
	return ;
}

Contact	&Contact::operator=(Contact const &rhs)
{
	if (this != &rhs)
	{
		this->_first_name = rhs._first_name;	
		this->_last_name = rhs._last_name;	
		this->_nickname = rhs._nickname;	
		this->_phone_number = rhs._phone_number;	
		this->_darkest_secret = rhs._darkest_secret;
	}
	return (*this);
}

void	Contact::ft_display_summary(int index) const
{
	std::cout << "|";
	std::cout << std::setw(10) << std::right << index;
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << Contact::_ft_format_summary(this->get_first_name());
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << Contact::_ft_format_summary(this->get_last_name());
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << Contact::_ft_format_summary(this->get_nickname());
	std::cout << "|";
	std::cout << std::endl;
}

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}

std::string	Contact::_ft_format_summary(const std::string &data)
{
	if (data.length() > 10)
		return (data.substr(0, 9) + ".");
	return (data);
}

std::ostream	&operator<<(std::ostream &o, Contact const &contact)
{
	o << "First Name:\t" << contact.get_first_name() << std::endl;
	o << "Last Name:\t" << contact.get_last_name() << std::endl;
    o << "Nickname:\t" << contact.get_nickname() << std::endl;
    o << "Phone Number:\t" << contact.get_phone_number() << std::endl;
    o << "Darkest Secret:\t" << contact.get_darkest_secret() << std::endl;
	return (o);
}
