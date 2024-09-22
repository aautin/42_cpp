/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:08:05 by aautin            #+#    #+#             */
/*   Updated: 2024/09/22 16:41:51 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

void print(Data *it) {
	std::cout << "Char: " << it->letter << std::endl;
	std::cout << "Int: " << it->number << std::endl;
	std::cout << "Fractional: " << it->fractional << std::endl;
}

int main() {
	Data number = {
		'a',
		static_cast<int>('a'),
		static_cast<float>('a')
	};

	print(&number);
	Data* numberPtr = Serializer::deserialize(Serializer::serialize(&number));
	print(numberPtr);
}
