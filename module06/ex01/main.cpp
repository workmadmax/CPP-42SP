/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:03:46 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/12 12:18:48 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data	dataOne;
	Data	*dataTwo;
	uintptr_t	s_ptr;
	uintptr_t	s_ptr2;

	dataOne.name = "Ecole";
	dataOne.number = 42;

	std::cout << "DataOne: " << dataOne.name << ", " << dataOne.number << std::endl;
	std::cout << "DataOne add: " << &dataOne << std::endl;
	s_ptr = Serializer::serialize(&dataOne);
	std::cout << "Data one serialize: " << s_ptr << std::endl;
	std::cout << std::endl;

	dataTwo = Serializer::deserialize(s_ptr);
	
	std::cout << "Data two name: " << dataTwo->name << ", " << dataTwo->number << std::endl;
	std::cout << "Data two add: " << dataTwo << std::endl;
	s_ptr2 = Serializer::serialize(dataTwo);
	std::cout << "Data two serialize: " << s_ptr2 << std::endl;
	std::cout << std::endl;

	if (dataTwo == &dataOne)
		std::cout << "Data two is equal to data one" << std::endl;
}