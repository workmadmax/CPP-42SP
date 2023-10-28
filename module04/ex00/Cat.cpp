/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:58:44 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 10:45:37 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << YELLOW << "Cat default constructor called" << RESET << std::endl;
};

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
	*this = copy;
};

Cat::~Cat()
{
	std::cout << RED << "Cat: destructor called" << RESET << std::endl;
};

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << YELLOW << "Cat assignation operator called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
};

void Cat::makeSound() const
{
	std::cout << YELLOW << "Cat: MeeoW!" << RESET << std::endl;
};

/* ************************************************************************** */