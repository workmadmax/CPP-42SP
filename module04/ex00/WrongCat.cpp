/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 09:38:20 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 15:40:48 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << GRAY << "WrongCat: default constructor called" << RESET << std::endl;
};

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << GRAY << "WrongCat: copy constructor called" << RESET << std::endl;
	*this = copy;
};

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat: destructor called" << RESET << std::endl;
};

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << GRAY << "WrongCat: assignation operator called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
};

void	WrongCat::makeSound(void) const
{
	std::cout << GRAY << "WrongCat: MuuuW MuuuW!" << RESET << std::endl;
};