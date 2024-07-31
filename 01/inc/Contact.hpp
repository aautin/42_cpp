/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:12:04 by aautin            #+#    #+#             */
/*   Updated: 2024/07/31 02:57:58 by aautin           ###   ########.fr       */
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

	public:
		/* Constructor-Destructor */
		Contact(void);
		~Contact(void);

		/* Setters */
		void	setFirstName(std::string &firstName);
		void	setLastName(std::string &lastName);
		void	setNickName(std::string &nickName);
		void	setPhoneNumber(__int64_t &phoneNumber);
		void	setDarkestSecret(std::string &darkestSecret);

		/* Getters */
		std::string		getFirstName() const;
		std::string		getLastName() const;
		std::string		getNickName() const;
		__int64_t		getPhoneNumber() const;
		std::string		getDarkestSecret() const;
};
