/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:04 by aautin            #+#    #+#             */
/*   Updated: 2024/09/28 20:30:13 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <fstream>

#include "BitcoinExchange.hpp"

/* >----------- Parsing -----------< */
static std::vector<std::string> fileToVector(std::string const & file) {
	std::vector<std::string> fileContent;

	std::fstream fileStream;
	fileStream.open(file.c_str(), std::fstream::in);

	std::string line;
	while (getline(fileStream, line))
		fileContent.push_back(line);

	fileStream.close();
	return fileContent;
}

static std::string getSeparator(
	std::vector<std::string> const & source,
	std::string const & leftColumn,
	std::string const & rightColumn) {

	std::size_t	leftIndex = source.front().find(leftColumn);
	std::size_t	rightIndex = source.front().find(rightColumn);
	if (leftIndex == std::string::npos || rightIndex == std::string::npos
		|| leftIndex + leftColumn.length() >= rightIndex)
		throw std::exception();
	
	std::string separator = source.front().substr(leftIndex + leftColumn.length(),
		rightIndex - leftColumn.length());

	std::vector<std::string>::const_iterator it = source.begin();
	while (it != source.end()) {
		if (it->find(separator) == std::string::npos
			|| it->find(separator) == it->rfind(separator))
			throw std::exception();
		it++;
	}

	return separator;
}

static std::pair<std::string, std::string> vectorToPair(
	std::vector<std::string> const & source,
	std::string const & separator) {

	std::pair<std::string, std::string> myPair;

	std::vector<std::string>::const_iterator it = source.begin();
	while (it != source.end()) {
		pair.
	}
}
/* <----------------------------> */


/* >----------- Cons/Destructors -----------< */
BitcoinExchange::BitcoinExchange(
	std::string const & coinTrackerFile = "data.csv",
	std::string const & belongingsTrackerFile = "input.txt") {
	
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other) {
	
}
/* <----------------------------> */


/* >----------- Overloads -----------< */
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & other) {
	
}
/* <----------------------------> */


/* >----------- Trackers -----------< */
void BitcoinExchange::trackCoin(std::string const & coinTrackerFile) {
	
}

void BitcoinExchange::trackBelongings(std::string const & belongingsTrackerFile) {
	
}

void BitcoinExchange::trackValues() {
	
}
/* <----------------------------> */
