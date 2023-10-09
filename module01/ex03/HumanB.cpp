/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:31:53 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/09 16:41:56 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << "HumanB constructor called" << std::endl;
};

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
};

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
};

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
};