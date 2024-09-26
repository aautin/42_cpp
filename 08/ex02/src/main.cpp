/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:51:16 by aautin            #+#    #+#             */
/*   Updated: 2024/09/26 16:02:31 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "MutantStack.hpp"

int main() {

	MutantStack<int> example;
	
	example.push(5);
	example.push(17);

	MutantStack<int> mstack = example;

	std::cout << "mtack top: " << mstack.top() << std::endl;

	std::cout << "mtack size: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "mtack size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	++it;
	--it;
	while (it != end)
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "mtack top: " << mstack.top() << std::endl;
	std::cout << "mtack size: " << mstack.size() << std::endl;

	std::stack<int> s(mstack);
	std::cout << "s top: " << s.top() << std::endl;
	std::cout << "s size: " << s.size() << std::endl;

	return 0;
}
