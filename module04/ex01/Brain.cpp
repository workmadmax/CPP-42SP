/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:25:59 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 16:28:48 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain(void)
{
	std::cout << PINK << "Brain: default constructor called" << RESET << std::endl;
};

Brain::Brain(const Brain &copy)
{
	std::cout << PINK << "Brain: copy constructor called" << RESET << std::endl;
	*this = copy;
};

Brain::~Brain()
{
	std::cout << RED << "Brain: destructor called" << RESET << std::endl;
};

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << PINK << "Brain: assignation operator called" << RESET << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return (*this);
};
