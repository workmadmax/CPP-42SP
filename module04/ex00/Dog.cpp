/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:56:07 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 10:46:58 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
};

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
	*this = copy;
};

Dog::~Dog()
{
	std::cout << RED << "Dog: destructor called" << RESET << std::endl;
};

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << GREEN << "Dog: assignation operator called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
};

void Dog::makeSound() const
{
	std::cout << GREEN << "Dog: Woof Woof!" << RESET << std::endl;
};

/* ************************************************************************** */