/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:55:33 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/10 11:54:40 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Usage: ./nosed <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	FileReplacer fileReplacer(filename, s1, s2);
	if (fileReplacer.replace()) {
		std::cout << "File " << filename << " successfully replaced" << std::endl;
	} else {
		std::cerr << "Error: " << fileReplacer.getErrorMessage() << std::endl;
		return (1);
	}
}