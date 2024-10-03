/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:04 by aautin            #+#    #+#             */
/*   Updated: 2024/10/03 17:32:53 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <fstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

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
			|| it->second.find(separator) != it->second.rfind(separator))
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

	if (year <= 0 || month <= 0 || day <= 0)
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

	if (value < -std::numeric_limits<int>::max()
		|| value > std::numeric_limits<float>::max()
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		throw std::exception();

	return value;
}

std::string formatDate(int year, int month, int day) {
    std::ostringstream oss;

    // Set padding for the year (4 digits)
    oss << std::setw(4) << std::setfill('0') << year << '-';

    // Set padding for the month (2 digits)
    oss << std::setw(2) << std::setfill('0') << month << '-';

    // Set padding for the day (2 digits)
    oss << std::setw(2) << std::setfill('0') << day;

    return oss.str();
}
/* <----------------------------> */


/* >----------- Cons/Destructors -----------< */
BitcoinExchange::BitcoinExchange(
	std::string const & coinTrackerFile,
	std::string const & belongingsTrackerFile) {
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

	content.erase(0);

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

	content.erase(0);

	std::map<int, std::string>::const_iterator it;
	int i = 0;
	for (it = content.begin(); it != content.end(); ++it) {
		std::string	left = it->second.substr(0, it->second.find(separator));
		std::string	right = it->second.substr(it->second.find(separator) + separator.length(),
			it->second.length() - it->second.find(separator) + separator.length());

		Date	key = strToKey(left);
		float	value = strToValue(right);

		if (value < 0)
			throw std::exception();

		_belongingsTracker.insert(std::make_pair(i , Pair(key, value)));
		i++;
	}
}

float BitcoinExchange::closestValue(Date it) {
	while (--it == true) {
		try {
			if (_coinTracker[it])
				return _coinTracker[it]; 
		}
		catch (...) {}
	}
	return _coinTracker.begin()->second;
}

void BitcoinExchange::printValues() {
	std::map<int, Pair>::const_iterator it;
	for (it = _belongingsTracker.begin(); it != _belongingsTracker.end(); ++it) {
		float value;
		try {
			value = _coinTracker[it->second.getDate()];
		}
		catch (std::out_of_range const &e) {
			value = closestValue(it->second.getDate());
		}

		/* print "YEAR-MONTH-DAY => belongingsQuantity = belongingsValue "*/
		std::cout << formatDate(it->second.getDate().getYear(),
			it->second.getDate().getMonth(), it->second.getDate().getDay());
		std::cout << " => " << it->second.getValue()
			<< " = " << value * it->second.getValue() << std::endl;
	}
}
/* <----------------------------> */
