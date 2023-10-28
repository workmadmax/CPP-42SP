/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 09:32:56 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 11:18:31 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "WrongAnimal";
	std::cout << ORANGE << "WrongAnimal: default constructor called" << RESET << std::endl;
};



WrongAnimal::WrongAnimal(const WrongAnimal &copy) : Animal(copy)
{
	std::cout << ORANGE << "WrongAnimal: copy constructor called" << RESET << std::endl;
	*this = copy;
};

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal: destructor called" << RESET << std::endl;
};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << ORANGE << "WrongAnimal: assignation operator called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
};

void WrongAnimal::makeSound() const
{
	std::cout << ORANGE << "WrongAnimal: Ablublubé" << RESET << std::endl;
};

