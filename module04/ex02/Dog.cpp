/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:25:51 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/29 19:27:26 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog"), _brain(new Brain())
{
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
};


Dog::Dog(const Dog &copy) : AAnimal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
	*this = copy;
};

Dog::~Dog(void)
{
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
	delete this->_brain;
};

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << GREEN << "Dog assignation operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		*this->_brain = *copy._brain;
	}
	return (*this);
};

void	Dog::makeSound(void) const
{
	std::cout << GREEN << "Dog: Woof Woof!" << RESET << std::endl;
};