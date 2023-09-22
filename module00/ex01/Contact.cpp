/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:17:49 by mdouglas          #+#    #+#             */
/*   Updated: 2023/09/21 19:00:29 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
};

Contact::~Contact()
{
};

// getters methods

std::string Contact::get_first_name() const
{
	return (this->_first_name);
};

std::string Contact::get_last_name() const
{
	return (this->_last_name);
};

std::string Contact::get_nickname() const
{
	return (this->_nickname);
};

std::string Contact::get_phone_number() const
{
	return (this->_phone_number);
};

std::string Contact::get_darkest_secret() const
{
	return (this->_darkest_secret);
};

// setters methods

/// @brief The function sets the first name of the contact.
/// @param first_name The first name of the contact.
/// @return int Returns 0 if the first name was set successfully, 1 otherwise.
int	Contact::set_first_name(std::string first_name)
{
	if (first_name == "")
		return (1);
	for (size_t i = 0; i < first_name.size(); i++)
	{
		if (!isalpha(first_name[i]))
		{
			if (isspace(first_name[i]))
				continue;
			else
				return (1);
		}
	}
	if (first_name.length() > 10)
	{
		first_name[9] = '.';
		first_name.erase(10, first_name.length() - 10);
	}
	this->_first_name = first_name;
	return (0);
};

/// @brief The function sets the last name of the contact.
/// @param last_name The last name of the contact.
/// @return int Returns 0 if the last name was set successfully, 1 otherwise.
int Contact::set_last_name(std::string last_name)
{
	if (last_name == "")
		return (1);
	for (size_t i = 0; i < last_name.size(); i++)
	{
		if (!isalpha(last_name[i]))
		{
			if (isspace(last_name[i]))
				continue;
			else
				return (1);
		}
	}
	this->_last_name = last_name;
	return (0);
};


/// @brief The function sets the nickname of the contact.
/// @param nickname The nickname of the contact.
/// @return int Returns 0 if the nickname was set successfully, 1 otherwise.
int Contact::set_nickname(std::string nickname)
{
	if (nickname == "")
		return (1);
	for (size_t i = 0; i < nickname.size(); i++)
	{
		if (!isalpha(nickname[i]))
		{
			if (isspace(nickname[i]))
				continue;
			else
				return (1);
		}
	}
	if (nickname.length() > 10)
	{
		nickname[9] = '.';
		nickname.erase(10, nickname.length() - 10);
	}
	this->_nickname = nickname;
	return (0);
};

/// @brief The function sets the phone number of the contact.
/// @param phone_number The phone number of the contact.
/// @return int Returns 0 if the phone number was set successfully, 1 otherwise.
int	Contact::set_phone_number(std::string phone_number)
{
	if (phone_number == "")
		return (1);
	for (size_t i = 0; i < phone_number.size(); i++)
	{
		if (!isdigit(phone_number[i]))
		{
			if (isspace(phone_number[i]))
				return (1);
		}
	}
	if (phone_number.length() > 10)
	{
		phone_number[9] = '.';
		phone_number.erase(10, phone_number.length() - 10);
	}
	this->_phone_number = phone_number;
	return (0);
};

/// @brief This function sets the darkest secret of the contact.
/// @param darkest_secret The darket secret of the contact.
/// @return int Returns 0 if the darkest secret was set successfully, 1 otherwise.
int Contact::set_darkest_secret(std::string darkest_secret)
{
	if (darkest_secret == "")
		return (1);
	if (darkest_secret.length() > 10)
	{
		darkest_secret[9] = '.';
		darkest_secret.erase(10, darkest_secret.length() - 10);
	}
	this->_darkest_secret = darkest_secret;
	return (0);
};