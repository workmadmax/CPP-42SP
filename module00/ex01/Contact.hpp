/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:28:31 by mdouglas          #+#    #+#             */
/*   Updated: 2023/09/21 14:15:23 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact;

class Contact
{
	public:
		Contact (
			const std::string& firstName, const std::string& lastName, const std::string& nickname,
			const std::string& phoneNumber, const std::string& darkestSecret
		);
		Contact (){}
	
	// methods
	std::string getFirstName() const { return firstName; }
	std::string getLastName() const { return lastName; }
	std::string getNickname() const { return nickname; }
	std::string getPhoneNumber() const { return phoneNumber; }
	std::string getDarkestSecret() const { return darkestSecret; }	

	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif