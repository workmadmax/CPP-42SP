/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:49:38 by mdouglas          #+#    #+#             */
/*   Updated: 2023/10/07 11:48:55 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_index = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "\033[31mPhoneBook destructor ...\033[0m" << std::endl;	
}

void	PhoneBook::addContact()
{
	int	flag = 0;
	
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string	phone_number = "";
	std::string	darkest_secret = "";

	while (std::cin.good() && (first_name.empty() || flag == 1))
	{
		flag = 0;
		std::cout << "First Name> ";
		getline(std::cin, first_name);
		if (first_name.empty())
			std::cout << "INVALID INPUT: non empty name!" << std::endl;
		if (_contacts[_index % 8].set_first_name(first_name) == 1)
		{
			std::cout << "INVALID INPUT: name not valid";
			flag = 1;
		}
	}

	while (std::cin.good() && (last_name.empty() || flag == 1))
	{
		flag = 0;
		std::cout << "Last Name> ";
		getline(std::cin, last_name);
		if (last_name.empty())
			std::cout << "INVALID INPUT: non empty name!" << std::endl;
		if (_contacts[_index % 8].set_last_name(last_name) == 1)
		{
			std::cout << "INVALID INPUT: name not valid";
			flag = 1;
		}
	}

	while (std::cin.good() && (nickname.empty() || flag == 1))
	{
		flag = 0;
		std::cout << "Nickname> ";
		getline(std::cin, nickname);
		if (nickname.empty())
			std::cout << "INVALID INPUT: non empty nickname!" << std::endl;
		if (_contacts[_index % 8].set_nickname(nickname) == 1)
		{
			std::cout << "INVALID INPUT: nickname not valid";
			flag = 1;
		}
	}
	
	while (std::cin.good() && (phone_number.empty() || flag == 1))
	{
		flag = 0;
		std::cout << "Phone Number> ";
		getline(std::cin, phone_number);
		if (phone_number.empty())
			std::cout << "INVALID INPUT: non empty phone number!" << std::endl;
		if (_contacts[_index % 8].set_phone_number(phone_number) == 1)
		{
			std::cout << "INVALID INPUT: phone number not valid";
			flag = 1;
		}
	}

	while (std::cin.good() && (darkest_secret.empty() || flag == 1))
	{
		flag = 0;
		std::cout << "Darkest secret: ";
		getline(std::cin, darkest_secret);
		if (darkest_secret.empty())
			std::cout << "INVALID INPUT: non empty secret!" << std::endl;
		_contacts[_index % 8].set_darkest_secret(darkest_secret);
	}
	this->_index++;
	std::cout << "Contact added!" << std::endl;
	std::cin.clear();
};

void	PhoneBook::searchContact()
{
	int	index = 0;
	std::string input;
	
	if (_index == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return ;
	}
	showContact();
	std::cout << "Enter index contact: " << std::endl;
	std::cout << "> ";
	std::cin >> input;
	index = std::atoi(input.c_str());
	if (std::cin.fail() || (index < 0) || (index > 7) || input.length() > 1)
		std::cout << "INVALID INPUT: index not valid!" << std::endl;
	else if (index >= _index)
		std::cout << "Contact is empty!" << std::endl;
	else
	{
		std::cout << "First Name: " << _contacts[index].get_first_name() << std::endl;
		std::cout << "Last Name: " << _contacts[index].get_last_name() << std::endl;
		std::cout << "Nickname: " << _contacts[index].get_nickname() << std::endl;
		std::cout << "Phone Number: " << _contacts[index].get_phone_number() << std::endl;
		std::cout << "Darkest Secret: " << _contacts[index].get_darkest_secret() << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}