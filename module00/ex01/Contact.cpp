/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:17:49 by mdouglas          #+#    #+#             */
/*   Updated: 2023/09/21 14:18:06 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class Contact;

Contact::Contact(
	const std::string &firstName, const std::string &lastName, const std::string &nickname,
	const std::string &phoneNumber, const std::string &darkestSecret
) : firstName(firstName), lastName(lastName), nickname(nickname),
	phoneNumber(phoneNumber), darkestSecret(darkestSecret)
{};
