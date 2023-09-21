/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:49:38 by mdouglas          #+#    #+#             */
/*   Updated: 2023/09/21 14:19:02 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook() : contactCount(0), currentIndex(0)
{
	contacts.resize(8);
}

void PhoneBook::addContact(const Contact &contact)
{
	if (contactCount < 8)
	{
		contacts[contactCount] = contact;
		contactCount++;
	}
	else
	{
		contacts[currentIndex] = contact;
		currentIndex = (currentIndex + 1) % 8;
	}
}

std::string PhoneBook::displayContacts() const
{
	std::string result;
	for (int i = 0; i < contactCount; i++)
	{
		result += "Index: " + std::to_string(i) + " | " + formatColumn(displayContacts()) + "\n";
	}
	return (result);
}

Contact PhoneBook::getContact(int index) const
{
	if (index >= 0 && index < contactCount)
		return (contacts[index]);
	else
		return (Contact("", "", "", "", ""));
}

std::string PhoneBook::formatColumn(const std::string &input) const
{
	if (input.length() <= 10)
		return (input + std::string(10 - input.length(), ' '));
	else
		return (input.substr(0, 9) + ".");
}

int main()
{

	PhoneBook phoneBook;
	Contact contact;

	phoneBook.addContact(Contact("madmax42", "", "", "", ""));
	phoneBook.addContact(Contact("garibaldo", "", "", "", ""));
	phoneBook.addContact(Contact("charle", "", "", "", ""));
	phoneBook.addContact(Contact("allan", "", "", "", ""));
	phoneBook.addContact(Contact("jacke", "", "", "", ""));
	phoneBook.addContact(Contact("jasmine", "", "", "", ""));
	phoneBook.addContact(Contact("rose", "", "", "", ""));
	phoneBook.addContact(Contact("laisa", "", "", "", ""));


	// testando adicionar mais que 8 contatos
	phoneBook.addContact(Contact("leila", "40028922", "", "", ""));
	phoneBook.addContact(Contact("lala", "33232333", "", "", ""));
	phoneBook.addContact(Contact("ale mendez", "10101010", "", "", ""));

	// print all contacts add

	for (int i = 0; i < 8; i++)
	{
		contact = phoneBook.getContact(i);
		std::cout << contact.getFirstName() << ": " << contact.getPhoneNumber() << std::endl;
	}

	return (0);
}