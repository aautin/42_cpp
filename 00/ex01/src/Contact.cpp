/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:32:38 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 02:00:20 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"
#include "userInterface.hpp"


/* Constructor-Destructor */
Contact::Contact(void)
{
	firstName = "Rick";
	lastName = "Astley";
	nickName = "Dick Spatsley";
	phoneNumber = "+44 7271987";
	darkestSecret = "Never Gonna Give You Up";
}
Contact::~Contact(void) {}


/* Setters */
void Contact::setFirstName(std::string const &newFirstName)
{
	this->firstName = newFirstName;
}
void Contact::setLastName(std::string const &newLastName)
{
	this->lastName = newLastName;
}
void Contact::setNickName(std::string const &newNickName)
{
	this->nickName = newNickName;
}
void Contact::setPhoneNumber(std::string const &newPhoneNumber)
{
	this->phoneNumber = newPhoneNumber;
}
void Contact::setDarkestSecret(std::string const &newDarkestSecret)
{
	this->darkestSecret = newDarkestSecret;
}


/* Getters */
std::string Contact::getFirstName() const
{
	return firstName;
}
std::string Contact::getLastName() const
{
	return lastName;
}
std::string Contact::getNickName() const
{
	return nickName;	
}
std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}
std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}


/* Others */
void	Contact::searchContact(int contactIndex) const
{
	std::cout << "|         " << contactIndex << "|";
	printField(this->getFirstName());
	std::cout << "|";
	printField(this->getLastName());
	std::cout << "|";
	printField(this->getNickName());
	std::cout << "|" << std::endl;
}
void	Contact::printContact() const
{
	printLine("Firstname: ", this->getFirstName().c_str());
	printLine("Lastname: ", this->getLastName().c_str());
	printLine("Nickname: ", this->getNickName().c_str());
	printLine("Phone number: ", this->getPhoneNumber().c_str());
	printLine("Darkest secret: ", this->getDarkestSecret().c_str());
}