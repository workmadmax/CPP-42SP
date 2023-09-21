/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:36:17 by mdouglas          #+#    #+#             */
/*   Updated: 2023/09/20 19:55:31 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <vector>

class Contact;

class PhoneBook
{
public:
	PhoneBook();

	// add new contact to the list
	void addContact(const Contact& contact);

	// show all contacts
	std::string displayContacts() const;

	// get contact by index
	Contact getContact(int index) const;

	


private:
	// format column to display 10 characters
	std::string formatColumn(const std::string& str) const;

	std::vector<Contact> contacts;
	int contactCount;
	int	currentIndex;	
};

#endif