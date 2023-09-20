/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:49:38 by mdouglas          #+#    #+#             */
/*   Updated: 2023/09/20 15:56:19 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

class PhoneBook
{
public:
	// construtor padrão
	PhoneBook()
	{
		// std::cout << "PhoneBook created" << std::endl;
		std::cout << "PhoneBook created" << std::endl;
	}

	// construtor personalizado
	PhoneBook(int value)
	{
		// std::cout << "PhoneBook created with value " << value << std::endl;
		std::cout << "PhoneBook created with value " << value << std::endl;
	}

	// function public member
	

	// destrutor
	~PhoneBook()
	{
		// std::cout << "PhoneBook destroyed" << std::endl;
		std::cout << "PhoneBook destroyed" << std::endl;
	}
};

int	main(void)
{
	PhoneBook phonebook;
	PhoneBook phonebook2(42);

	return (0);
}