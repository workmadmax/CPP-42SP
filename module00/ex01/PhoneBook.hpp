/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:36:17 by mdouglas          #+#    #+#             */
/*   Updated: 2023/10/07 11:05:57 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <vector>
# include "Contact.hpp"

# define MAX_CONTACT 8

class Contact;

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContact();
	void	showContact() const;
	void	showMenu();

	
private:
	int		_index;
	Contact _contacts[MAX_CONTACT];
	

};

#endif