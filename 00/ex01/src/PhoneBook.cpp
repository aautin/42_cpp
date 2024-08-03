/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:52:41 by aautin            #+#    #+#             */
/*   Updated: 2024/08/03 21:10:36 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"
#include "userInterface.hpp"

/* Constructor-Destructor */
PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < MAX_CONTACTS_NBR; i++)
		this->contacts[i] = new Contact;
	this->contactsNumber = 8;
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


/* Getters */
Contact	*PhoneBook::getContact(int contactIndex) const
{
	return this->contacts[contactIndex];
}
int		PhoneBook::getContactsNumber() const
{
	return this->contactsNumber;
}


/* Algorithm */
void	PhoneBook::printBook() const
{
	int	contactsNumber = this->getContactsNumber();

	for (int i = 0; i < contactsNumber; i++)
		this->contacts[i]->searchContact(i);
	printLine(NULL, EDGE);
}
void	PhoneBook::search(int consecutiveFails)
{
	if (consecutiveFails == 0) {
		printLine(NULL, EDGE);
		printBook();
	}

	std::string index = readLine("Contact index");
	if (index.length() > 1
		|| !('0' <= index[0] && index[0] < this->getContactsNumber() + '0')) {
		printInvalid(++consecutiveFails, "index");
		if (consecutiveFails < 3)
			this->search(consecutiveFails);
	}
	else
		this->contacts[index[0] - '0']->printContact();
	return ;
}
void	PhoneBook::add(Contact *newContact)
{
	printLine(NULL, EDGE);

	char prompts[5][20] = {"Firstname", "Lastname", "Nickname",
		"Phone number", "Darkest secret"};
	bool (*isValid[5])(std::string const &) = {&isValidName, &isValidName, &isValidName,
		&isValidPhoneNumber, &isNotEmptyString};
	void (Contact::*set[5])(std::string const &) = {&Contact::setFirstName, &Contact::setLastName,
		&Contact::setNickName, &Contact::setPhoneNumber, &Contact::setDarkestSecret};

	for (int i = 0; i < 5; i++) {
		int consecutiveFails = 0;
		while (consecutiveFails < 3) {
			std::string input = readLine(prompts[i]);
			if (!isValid[i](input)) {
				printInvalid(++consecutiveFails, "content");
				if (consecutiveFails == 3) {
					delete newContact;
					return ;
				}
			}
			else {
				(newContact->*set[i])(input);
				break ;
			}
		}
	}

	this->setContact(newContact);
	return ;
}
void	PhoneBook::command(int consecutiveFails)
{
	if (consecutiveFails == 0)
		printLine(NULL, EDGE);

	std::string command = readLine("Phonebook");
	if (command.compare("SEARCH") == 0) {
		if (this->getContactsNumber() != 0)
			this->search(0);
		else
			printLine(NULL, "No contact found.");
	}
	else if (command.compare("ADD") == 0)
		this->add(new Contact);
	else if (command.compare("EXIT") == 0)
		return ;
	else {
		printInvalid(++consecutiveFails, "command");
		if (consecutiveFails == 3)
			return ;
		this->command(consecutiveFails);
		return ;
	}

	this->command(0);
}
