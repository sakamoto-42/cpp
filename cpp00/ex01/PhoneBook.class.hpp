/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:08:13 by julien            #+#    #+#             */
/*   Updated: 2025/05/27 12:44:29 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include <string>
# include "Contact.class.hpp"

class	PhoneBook
{
	public:
		PhoneBook(void);
		PhoneBook(PhoneBook const &src);
		virtual	~PhoneBook(void);

		PhoneBook &operator=(PhoneBook const &rhs);

		void	ft_add_contact(void);
		void	ft_search_contact(void);

	private:
		void		_ft_print_add_contact_warning(void);
		static bool		_ft_get_contact_field(const std::string &field,
			std::string &input);
		static bool		_ft_get_contact_fields(
			std::string &first_name, std::string &last_name,
			std::string &nickname, std::string &phone_number,
			std::string &darkest_secret);
		void _ft_save_contact(const Contact &new_contact);

		Contact	_contacts[8];
		int		_contact_count;
		int		_next_contact_index;
};

std::ostream	&operator<<(std::ostream &o, PhoneBook const &i);

#endif
