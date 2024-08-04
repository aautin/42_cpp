/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:55:02 by aautin            #+#    #+#             */
/*   Updated: 2024/08/04 23:02:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class FileConten

static std::string	&fileToString(std::string &srcFile)
{
	std::ifstream		in(srcFile.c_str(), std::ifstream::in);
	std::stringstream	buffer;

	buffer << in.rdbuf();

	std::string contents(buffer.str());

	return contents;
}

static void	replaceFile(std::string &srcFile, std::string &resultFile,
						std::string &target, std::string &replacement)
{
	std::string	srcFileContent = fileToString(srcFile);

	(void) resultFile;
	(void) target;
	(void) replacement;
	(void) resultFile;
}

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Wrong arguments" << std::endl;
		std::cout << "Must be: [filename] [string_target] [string_replacement]" << std::endl;
	}
	else {
		std::string srcFile = argv[argc - 3];
		std::string resultFile = srcFile + ".replace";
		std::string	target = argv[argc - 2];
		std::string	replacement = argv[argc - 1];
	
		replaceFile(srcFile, resultFile, target, replacement);
	}
}
