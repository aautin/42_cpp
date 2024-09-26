/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:10 by aautin            #+#    #+#             */
/*   Updated: 2024/09/26 16:49:00 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <string>
# include <vector>

typedef struct sDate {
	int year;
	int month;
	int day;
}	tDate;

typedef struct sTrackerPoint {
	tDate	date;
	float	value;
}	trackerPoint;

class BitcoinExchange
{
	public:
		/* >------ Cons/Destructors ------< */
		BitcoinExchange(std::string const & coinTrackerFilename = "data.csv",
			std::string const & wealthTrackerFilename = "input.txt");
		BitcoinExchange(BitcoinExchange const & other);
		~BitcoinExchange();
		
		/* >------ Overloads ------< */
		BitcoinExchange&	operator=(BitcoinExchange const & other);

	private:
		std::vector<trackerPoint> _coinTracker;
		std::vector<trackerPoint> _wealthTracker;
};

#endif