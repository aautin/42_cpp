/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:55:29 by aautin            #+#    #+#             */
/*   Updated: 2024/08/08 21:25:23 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl2_0;

	harl2_0.complain("DEBUG");
	harl2_0.complain("INFO");
	harl2_0.complain("WARNING");
	harl2_0.complain("ERROR");

	harl2_0.complain("OTHER");
	harl2_0.complain("");

	harl2_0.complain("INFO");
	harl2_0.complain("INFO");
}
