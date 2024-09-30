/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:04 by aautin            #+#    #+#             */
/*   Updated: 2024/09/30 17:42:26 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>

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

static Date strToKey(std::string const & str) {
	if (str.length() != 10 || str[4] != '-' || str[7] != '-')
		throw std::exception();

	std::string::const_iterator it;
	for (it = str.begin(); it != str.end(); ++it) {
		if (it - str.begin() != 4 && (it - str.begin() != 7) && !isdigit(*it))
			throw std::exception();
	}

	long year = strtod(str.c_str(), NULL);
	long month = strtod(&str[5], NULL);
	long day = strtod(&str[8], NULL);

	if (year < 0 || month < 0 || day < 0)
		throw std::exception();
	if (year > 2024 || month > 12 || day > 31)
		throw std::exception();

	return Date(year, month, day);
}

static float strToValue(std::string const & str) {
	char *strPtr;
	double value = strtod(str.c_str(), &strPtr);

	if (*strPtr != '\0')
		throw std::exception();

	if (value < std::numeric_limits<float>::min()
		|| value > std::numeric_limits<float>::max()
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		throw std::exception();

	return value;
}
/* <----------------------------> */


/* >----------- Cons/Destructors -----------< */
BitcoinExchange::BitcoinExchange(
	std::string const & coinTrackerFile = "data.csv",
	std::string const & belongingsTrackerFile = "input.txt") {
	trackCoin(coinTrackerFile);
	trackBelongings(belongingsTrackerFile);
	printValues();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other) {
	*this = other;
}
/* <----------------------------> */


/* >----------- Overloads -----------< */
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & other) {
	_coinTracker = other._coinTracker;
	_belongingsTracker = other._belongingsTracker;

	return *this;
}
/* <----------------------------> */


/* >----------- Trackers -----------< */
void BitcoinExchange::trackCoin(std::string const & coinTrackerFile) {
	std::map<int, std:: string>	content = fileToMap(coinTrackerFile);
	std::string					separator = getSeparator(content,
														 LEFT_NAME, COIN_RIGHT_NAME);

	std::map<int, std::string>::const_iterator it;
	for (it = content.begin(); it != content.end(); ++it) {
		std::string	left = it->second.substr(0, it->second.find(separator));
		std::string	right = it->second.substr(it->second.find(separator) + separator.length(),
			it->second.length() - it->second.find(separator) + separator.length());

		Date	key = strToKey(left);
		float	value = strToValue(right);

		_coinTracker.insert(std::make_pair(key, value));
	}
}

void BitcoinExchange::trackBelongings(std::string const & belongingsTrackerFile) {
	std::map<int, std:: string>	content = fileToMap(belongingsTrackerFile);
	std::string					separator = getSeparator(content,
														 LEFT_NAME, BELONGINGS_RIGHT_NAME);

	std::map<int, std::string>::const_iterator it;
	for (it = content.begin(); it != content.end(); ++it) {
		std::string	left = it->second.substr(0, it->second.find(separator));
		std::string	right = it->second.substr(it->second.find(separator) + separator.length(),
			it->second.length() - it->second.find(separator) + separator.length());

		Date	key = strToKey(left);
		float	value = strToValue(right);

		if (value < 0)
			throw std::exception();

		_belongingsTracker.insert(std::make_pair(key, value));
	}
}

static Date findClosest(Date const &it) {
	
}

void BitcoinExchange::printValues() {
	std::map<Date, float>::const_iterator it;
	for (it = _belongingsTracker.begin(); it != _belongingsTracker.end(); ++it) {
		float value;
		try {
			value = _coinTracker[it->first];
		}
		catch (std::out_of_range const &e) {
			value = _coinTracker[findClosest(it->first)];
			continue ;
		}
		/* print "YEAR-MONTH-DAY => belongingsQuantity => belongingsValue "*/
	}
}
/* <----------------------------> */
