/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:37:05 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 16:38:30 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << YELLOW << "Cat: default constructor called" << RESET << std::endl;
	this->_brain = new Brain();
};

Cat::Cat(const Cat &copy) : Animal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << YELLOW << "Cat: copy constructor called" << RESET << std::endl;
	*this = copy;
};

Cat::~Cat()
{
	std::cout << RED << "Cat: destructor called" << RESET << std::endl;
	delete this->_brain;
};

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << YELLOW << "Cat: assignation operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		*this->_brain = *copy._brain;
	}
	return (*this);
};

void Cat::makeSound(void) const
{
	std::cout << YELLOW << "Cat: \"Meow!\"" << RESET << std::endl;
};
