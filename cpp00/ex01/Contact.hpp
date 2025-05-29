/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:08:16 by julien            #+#    #+#             */
/*   Updated: 2025/05/28 21:41:45 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
	public:
		Contact(void);
		Contact(
			const std::string &first_name,
			const std::string &last_name,
			const std::string &nickname,
			const std::string &phone_number,
			const std::string &darkest_secret
		);
		Contact(Contact const &src);
		virtual	~Contact(void);

		Contact &operator=(Contact const &rhs);

		void		ft_display_summary(int index) const;

		std::string			get_first_name(void) const;
		std::string			get_last_name(void) const;
		std::string			get_nickname(void) const;
		std::string			get_phone_number(void) const;
		std::string			get_darkest_secret(void) const;

	private:
		static std::string	_ft_format_summary(const std::string &data);

		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

std::ostream	&operator<<(std::ostream &o, Contact const &contact);

#endif
