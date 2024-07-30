/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:12:04 by aautin            #+#    #+#             */
/*   Updated: 2024/07/30 21:10:14 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
	private:
		/* Variables */
		std::string		firstName;
		std::string		lastName;
		std::string		nickName;
		__int64_t		phoneNumber;
		std::string		darkestSecret;

		/* Setters */
		bool	setFirstName(std::string const name);
		bool	setLastName(std::string const name);
		bool	setNickName(std::string const name);
		bool	setPhoneNumber(std::string const number);
		bool	setDarkestSecret(std::string const secret);

	public:
		/* Constructor/Destructor */
		Contact(void);
		~Contact(void);

		Contact(std::string const &firstName, std::string const &lastName,
				std::string const &nickName, std::string const &phoneNumber,
				std::string const &darkestSecret);

		/* Getters */
		std::string		getFirstName() const;
		std::string		getLastName() const;
		std::string		getNickName() const;
		__int64_t		getPhoneNumber() const;
		std::string		getDarkestSecret() const;
};
