/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:18:42 by aautin            #+#    #+#             */
/*   Updated: 2024/08/01 03:29:11 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#define MAX_CONTACTS_NBR 8

class PhoneBook
{
	private:
		/* Variables */
		Contact		*contacts[MAX_CONTACTS_NBR];
		int			contactsNumber;

	public:
		/* Constructor-Destructor */
		PhoneBook(void);
		~PhoneBook(void);

		/* Setters */
		void	setContact(Contact *newContact);
		void	setContactsNumber(int newContactsNumber);

		/* Getters */
		Contact		*getContact(int contactIndex) const;
		int			getContactsNumber() const;
};
