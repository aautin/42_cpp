/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:12:04 by aautin            #+#    #+#             */
/*   Updated: 2024/07/31 22:41:57 by aautin           ###   ########.fr       */
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
		std::string		darkestSecret;
		long			phoneNumber;

	public:
		/* Constructor-Destructor */
		Contact(void);
		~Contact(void);

		/* Setters */
		void	setFirstName(std::string &newFirstName);
		void	setLastName(std::string &newLastName);
		void	setNickName(std::string &newNickName);
		void	setDarkestSecret(std::string &newDarkestSecret);
		void	setPhoneNumber(long newPhoneNumber);

		/* Getters */
		std::string		getFirstName() const;
		std::string		getLastName() const;
		std::string		getNickName() const;
		std::string		getDarkestSecret() const;
		long			getPhoneNumber() const;
};
