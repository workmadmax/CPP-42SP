/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:30:39 by madmax42          #+#    #+#             */
/*   Updated: 2023/09/22 11:03:07 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::showContact() const
{
	std::cout << "|-------------------------------------------|\n"
				<<"|------------- CONTACT LIST  --------------|\n"
				<<"|-------------------------------------------|\n"
				<<"|     INDEX|FIRST NAME| LAST NAME| NICKNAME |\n"
				<<"|-------------------------------------------|\n";
	
	for (int i = 0; i < 8; i++)
	{
		std::cout << '|' << std::setw(10) << i + 1 << '|';
		std::cout << '|' << std::setw(10) << _contacts[i].get_first_name() << '|';
		std::cout << '|' << std::setw(10) << _contacts[i].get_last_name() << '|';
		std::cout << '|' << std::setw(10) << _contacts[i].get_nickname() << '|';
		std::cout << '|' << std::endl;
	}
}

void	PhoneBook::showMenu()
{
	std::cout << "|---------------------WELCOME---------------------|" << std::endl;
	std::cout << "|---------------------MENU---------------------|" << std::endl;
	std::cout << "|---------------------(1)-ADD---------------------|" << std::endl;
	std::cout << "|---------------------(2)-SEARCH---------------------|" << std::endl;
	std::cout << "|---------------------(3)-EXIT---------------------|" << std::endl;
	std::cout << "|--------------------------------------------------|" << std::endl;
}

int	main(void)
{
	PhoneBook phonebook;
	std::string	input;
	phonebook.showMenu();
	std::cout << "> ";
	while (std::cin.good() && getline(std::cin, input))
	{
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "INVALID INPUT: " << input << std::endl;
		phonebook.showMenu();
		std::cout << "> ";
	}
	return (0);
}