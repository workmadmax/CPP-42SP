/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:45:00 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 10:48:32 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << BLUE << "Animal default constructor called" << RESET << std::endl;
};

Animal::Animal(std::string const &type) : _type(type)
{
	std::cout << BLUE << "Animal type constructor called" << RESET << std::endl;
};

Animal::Animal(const Animal &copy)
{
	std::cout << BLUE << "Animal copy constructor called" << RESET << std::endl;
	*this = copy;
};

Animal::~Animal()
{
	std::cout << RED << "Animal: destructor called" << RESET << std::endl;
};

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << BLUE << "Animal assignation operator called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
};

std::string Animal::getType() const
{
	return (this->_type);
};

void Animal::makeSound() const
{
	std::cout << BLUE << "Animal: makes a unknown sound" << RESET << std::endl;
};

/* ************************************************************************** */