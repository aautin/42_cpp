/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:52:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/02 01:07:13 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"
#include "userInterface.hpp"

/* Constructor-Destructor */
PhoneBook::PhoneBook(void)
{
	this->contacts[0] = new Contact;
	for (int i = 1; i < MAX_CONTACTS_NBR; i++)
		this->contacts[i] = NULL;
	this->contactsNumber = 1;
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
	this->consecutiveFailsNumber = newConsecutiveFailsNumber;
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


/* Algorithm */
void	PhoneBook::printContacts() const
{
	int	contactsNumber = this->getContactsNumber();

	printLine(EDGE);
	for (int i = 0; i < contactsNumber; i++)
		this->contacts[i]->searchContact(i);
	printLine(EDGE);
}
void	PhoneBook::search(int consecutiveFails)
{
	if (this->getContactsNumber() != 0) {
		if (consecutiveFails == 0)
			printContacts();
		std::string index = readLine("Contact index");
		if (index.length() > 1 || !('0' <= index[0] && index[0] <= this->getContactsNumber() + '0' - 1)) {
			printInvalid(consecutiveFails + 1, "index");
			this->search(consecutiveFails + 1);
		}
		else
			this->contacts[index[0] - '0']->printContact();
	}
	else
		printLine("No contact found.");
	printLine(EDGE);
	return ;
}
void	PhoneBook::add(int consecutiveFails)
{
	this->setConsecutiveFailsNumber(consecutiveFails);
	return ;
}