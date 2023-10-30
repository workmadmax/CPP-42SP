/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:17:07 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/29 19:37:40 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << GREEN << "AAnimal default constructor called" << RESET << std::endl;
};

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << GREEN << "AAnimal copy constructor called" << RESET << std::endl;
	*this = copy;
};

AAnimal::AAnimal(std::string const &type) : _type(type)
{
	std::cout << GREEN << "AAnimal type constructor called" << RESET << std::endl;
};

AAnimal::~AAnimal(void)
{
	std::cout << RED << "AAnimal destructor called" << RESET << std::endl;
};

AAnimal	&AAnimal::operator=(const AAnimal &copy)
{
	std::cout << GREEN << "AAnimal assignation operator called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
};

std::string		AAnimal::getType(void) const
{
	return (this->_type);
};