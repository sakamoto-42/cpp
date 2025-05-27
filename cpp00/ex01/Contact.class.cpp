/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:08:19 by julien            #+#    #+#             */
/*   Updated: 2025/05/26 18:54:24 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
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

std::ostream	&operator<<(std::ostream &o, Contact const &i)
{
	(void)i;
	return (o);
}