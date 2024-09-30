/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:04 by aautin            #+#    #+#             */
/*   Updated: 2024/09/30 16:02:17 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <fstream>

#include "BitcoinExchange.hpp"

/* >----------- Parsing -----------< */
static std::map<int, std::string> fileToMap(std::string const & file) {
	std::map<int, std::string> fileContent;

	std::fstream fileStream;
	fileStream.open(file.c_str(), std::fstream::in);

	std::string	line;
	int			key = 0;
	while (getline(fileStream, line))
		fileContent[key++] = std::string(line);

	fileStream.close();
	return fileContent;
}

static std::string getSeparator(
	std::map<int, std::string> & source,
	std::string const & leftColumn,
	std::string const & rightColumn) {

	std::size_t	leftIndex = source[0].find(leftColumn);
	std::size_t	rightIndex = source[0].find(rightColumn);
	if (leftIndex == std::string::npos || rightIndex == std::string::npos
		|| leftIndex + leftColumn.length() >= rightIndex)
		throw std::exception();
	
	std::string separator = source[0].substr(leftIndex + leftColumn.length(),
		rightIndex - leftColumn.length());

	std::map<int, std::string>::const_iterator it = source.begin();
	while (it != source.end()) {
		if (it->second.find(separator) == std::string::npos
			|| it->second.find(separator) == it->second.rfind(separator))
			throw std::exception();
		it++;
	}

	return separator;
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
	std::map<int, std::string>	content = fileToMap(coinTrackerFile);
	std::string					separator = getSeparator(content, "date", "exchange_rate");

	std::map<int, std::string>::const_iterator it;
	for (it = content.begin(); it != content.end(); ++it) {
		
	}
}

void BitcoinExchange::trackBelongings(std::string const & belongingsTrackerFile) {
	
}

void BitcoinExchange::trackValues() {
	
}
/* <----------------------------> */
