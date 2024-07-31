/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:52:41 by aautin            #+#    #+#             */
/*   Updated: 2024/07/31 22:45:39 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

/* Constructor-Destructor */
PhoneBook::PhoneBook(void)
{
	this->contactsNumber = 0;
}
PhoneBook::~PhoneBook(void) {}

/* Setters */
void	PhoneBook::setContact(Contact newContact)
{
	int contactsNumber = this->getContactsNumber();
	for (int i = contactsNumber - 1; i >= 0; i--)
		this->contacts[i + 1] = this->contacts[i];

	this->contacts[0] = newContact;
	if (contactsNumber != MAX_CONTACTS_NBR)
		setContactsNumber(contactsNumber + 1);
}
void	PhoneBook::setContactsNumber(int newContactsNumber)
{
	this->contactsNumber = newContactsNumber;
}

/* Getters */
Contact		PhoneBook::getContact(int contactIndex) const
{
	return contacts[contactIndex];
}

int	PhoneBook::getContactsNumber()
{
	return this->contactsNumber;
}

