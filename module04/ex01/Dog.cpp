/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:21:26 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 16:38:13 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << GREEN << "Dog: default constructor called" << RESET << std::endl;
	this->_brain = new Brain();
};

Dog::Dog(const Dog &copy) : Animal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << GREEN << "Dog: copy constructor called" << RESET << std::endl;
	*this = copy;
};

Dog::~Dog()
{
	std::cout << RED << "Dog: destructor called" << RESET << std::endl;
	delete this->_brain;
};

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << GREEN << "Dog: assignation operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		*this->_brain = *copy._brain;
	}
	return (*this);
};

void Dog::makeSound(void) const
{
	std::cout << GREEN << "Dog: \"Woof!\"" << RESET << std::endl;
};
