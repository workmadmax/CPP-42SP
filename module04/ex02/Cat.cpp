/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:23:48 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/29 19:38:30 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << YELLOW << "Cat default constructor called" << RESET << std::endl;
};

Cat::Cat(const Cat &copy) : AAnimal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
	*this = copy;
};

Cat::~Cat(void)
{
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
	delete this->_brain;
};

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << YELLOW << "Cat assignation operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		*this->_brain = *copy._brain;
	}
	return (*this);
};

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << "Cat: Meow Meow!" << RESET << std::endl;
};