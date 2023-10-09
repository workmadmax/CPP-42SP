/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:29:30 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/09 14:55:45 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string YELLOW = "\033[1;33m";
const std::string BLUE = "\033[1;34m";
const std::string RESET = "\033[0m";

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPointer = &string;
	std::string&	stringReference = string;

	std::cout << RED << "print memory address : " << std::endl;
	std::cout << std::endl;
	
	std::cout << GREEN << "str: " << &string << std::endl;
	std::cout << BLUE << "strPtr: " << stringPointer << std::endl;
	std::cout << YELLOW << "strRef: " << &stringReference << std::endl;
	std::cout << std::endl;

	std::cout << RED << "print value : " << std::endl;
	std::cout << std::endl;
	
	std::cout << GREEN << "str: " << string << std::endl;
	std::cout << BLUE << "strPtr: " << *stringPointer << std::endl;
	std::cout << YELLOW << "strRef: " << stringReference << std::endl;
	return (0);
}