/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:10 by aautin            #+#    #+#             */
/*   Updated: 2024/09/30 17:40:36 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# define LEFT_NAME "date"
# define COIN_RIGHT_NAME "exchange_rate"
# define BELONGINGS_RIGHT_NAME "value"

# include <string>
# include <map>

class Date
{
	public:
		/* >------ Cons/Destructors ------< */
		Date() : _year(0), _month(0), _day(0) {}
		Date(int year, int month, int day)
		: _year(year), _month(month), _day(day) {}
		Date(Date const & other)
		: _year(other._year), _month(other._month), _day(other._day) {}
		~Date() {}
		
		/* >------ Overloads ------< */
		Date&	operator=(Date const & other) {
			_year = other._year;
			_month = other._month;
			_day = other._day;
		}
		bool	operator<(Date const & other) {
			if (_year < other._year
				|| _year == other._year && _month < other._month
				|| (_year == other._year && _month == other._month
					&& _day < other._day))
					return true;
			return false;
		}

	private:
		unsigned int	_year;
		unsigned int	_month;
		unsigned int	_day;
};

class BitcoinExchange
{
	public:
		/* >------ Cons/Destructors ------< */
		BitcoinExchange(
			std::string const & coinTrackerFile = "data.csv",
			std::string const & belongingsTrackerFile = "input.txt");
		BitcoinExchange(BitcoinExchange const & other);
		~BitcoinExchange() {}
		
		/* >------ Overloads ------< */
		BitcoinExchange&	operator=(BitcoinExchange const & other);

		/* >------ Trackers ------< */
		void				trackCoin(std::string const & coinTrackerFile);
		void				trackBelongings(std::string const & belongingsTrackerFile);
		void				printValues();

	private:
		std::map<Date, float>	_coinTracker;
		std::map<Date, float>	_belongingsTracker;
};

#endif