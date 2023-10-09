/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:02:24 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/09 16:30:44 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Weapon constructor called" << std::endl;
};

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon constructor called" << std::endl;
};

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;
};

std::string const&	Weapon::getType(void)
{
	return (this->_type);
};

void				Weapon::setType(std::string type)
{
	this->_type = type;
};