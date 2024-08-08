/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:55:02 by aautin            #+#    #+#             */
/*   Updated: 2024/08/08 19:10:14 by aautin           ###   ########.fr       */
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
void	File::replace(std::string const target, std::string const replacement)
{
	std::string	newContent;

	for (int i = 0; i < content.length();) {
		if (content.compare(i, target.length(), target) == 0) {
			newContent.append(replacement);
			i += target.length();
		}
		else {
			newContent.push_back(content[i]);
			i++;
		}
	}

	content = newContent;
}
bool	File::load(std::string const sourceFileName)
{
	std::ifstream	stream(sourceFileName.c_str(), std::iostream::in);

	if (!stream.is_open()) {
		std::cout << "An error occured during " << sourceFileName << " opening" << std::endl;
		return FAILURE;
	}

	std::string content((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

	this->content = content;
	return SUCCESS;
}
bool	File::stream(std::string const &destinationFileName) const
{
	std::ofstream	stream(destinationFileName.c_str(), std::iostream::out);

	if (!stream.is_open()) {
		std::cout << "An error occured during " << destinationFileName << " opening" << std::endl;
		return FAILURE;
	}

	stream.write(content.c_str(), content.length());
	return SUCCESS;
}
