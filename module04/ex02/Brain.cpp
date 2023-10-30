/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:28:16 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/29 19:29:33 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << PINK << "Brain default constructor called" << RESET << std::endl;
};

Brain::Brain(const Brain &copy)
{
	std::cout << PINK << "Brain copy constructor called" << RESET << std::endl;
	*this = copy;
};

Brain::~Brain(void)
{
	std::cout << RED << "Brain destructor called" << RESET << std::endl;
};

Brain	&Brain::operator=(const Brain &copy)
{
	std::cout << PINK << "Brain assignation operator called" << RESET << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return (*this);
};