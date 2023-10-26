/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:34:10 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/26 10:38:35 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default")
{
	std::cout << "FragTrap default contructor called" << std::endl;
};

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap name contructor called" << std::endl;
};

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "FragTrap copy contructor called" << std::endl;
	*this = copy;
};

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
};

FragTrap	&FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
};

void		FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": HighFivesGuys!" << std::endl;
};