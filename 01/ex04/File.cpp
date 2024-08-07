/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:55:02 by aautin            #+#    #+#             */
/*   Updated: 2024/08/08 00:22:11 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

#include "File.hpp"

/* Constructor-Destructor */
File::File(std::string &name) : name(name) {}
File::~File() {}


/* Getters */
std::string	&File::getName() const
{
	return this->name;
}


/* Others */
void	File::replace(std::string const &target, std::string const &replacement)
{
	for (std::string::iterator it = content.begin(); it != content.end(); it++) {
		/* replace here */
	}
}
bool	File::load(std::string const &sourceFileName)
{
	std::ifstream	stream(sourceFileName.c_str(), std::ifstream::in);

	if (!stream.is_open()) {
		std::cout << "An error occured during " << sourceFileName << " opening" << std::endl;
		return FAILURE;
	}

	std::string content((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

	// Print the content to verify (optional)
	std::cout << content << std::endl;
	
	return SUCCESS;
}
// void	File::stream(std::string const &destinationFileName) const ;