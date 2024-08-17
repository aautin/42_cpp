/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:55:29 by aautin            #+#    #+#             */
/*   Updated: 2024/08/17 16:55:45 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl2_0;

	harl2_0.Harl::complain("DEBUG");
	harl2_0.Harl::complain("INFO");
	harl2_0.Harl::complain("WARNING");
	harl2_0.Harl::complain("ERROR");

	harl2_0.Harl::complain("OTHER");
	harl2_0.Harl::complain("");

	harl2_0.Harl::complain("INFO");
	harl2_0.Harl::complain("INFO");
}
