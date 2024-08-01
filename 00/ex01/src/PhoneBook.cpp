/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:52:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/01 22:09:38 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

/* Constructor-Destructor */
PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < MAX_CONTACTS_NBR; i++)
		this->contacts[i] = NULL;
	this->contactsNumber = 0;
	this->consecutiveFailsNumber = 0;
}
PhoneBook::~PhoneBook(void) {
	for (int i = 0; i < MAX_CONTACTS_NBR; i++)
		delete this->contacts[i];
}


/* Setters */
void	PhoneBook::setContact(Contact *newContact)
{
	int contactsNumber = this->getContactsNumber();

	if (contactsNumber != MAX_CONTACTS_NBR)
		setContactsNumber(contactsNumber + 1);
	else {
		delete this->contacts[MAX_CONTACTS_NBR - 1];
		contactsNumber--;
	}

	for (int i = contactsNumber - 1; i >= 0; i--)
		this->contacts[i + 1] = this->contacts[i];

	this->contacts[0] = newContact;
}
void	PhoneBook::setContactsNumber(int newContactsNumber)
{
	this->contactsNumber = newContactsNumber;
}
void	PhoneBook::setConsecutiveFailsNumber(int newConsecutiveFailsNumber)
{
	this->consecutiveFailsNumber = consecutiveFailsNumber;
}

/* Getters */
Contact	*PhoneBook::getContact(int contactIndex) const
{
	return this->contacts[contactIndex];
}
int		PhoneBook::getContactsNumber() const
{
	return this->contactsNumber;
}
int		PhoneBook::getConsecutiveFailsNumber() const
{
	return this->consecutiveFailsNumber;
}
