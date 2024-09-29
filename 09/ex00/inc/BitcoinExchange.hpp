/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:10 by aautin            #+#    #+#             */
/*   Updated: 2024/09/28 20:03:48 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <string>
# include <utility>
# include <vector>

typedef struct sDate {
	int year;
	int month;
	int day;
}	tDate;

typedef struct sTrackerPoint {
	tDate	date;
	float	value;
}	trackPoint;

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
		void	trackCoin(std::string const & coinTrackerFile);
		void	trackBelongings(std::string const & belongingsTrackerFile);
		void	trackValues();

	private:
		std::vector<trackPoint>	_coinTracker;
		std::vector<trackPoint>	_belongingsTracker;
		std::vector<trackPoint>	_valuesTracker;
};

#endif