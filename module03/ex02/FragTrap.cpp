/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:34:10 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/26 12:03:29 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "Default FragTrap contructor called" << RESET << std::endl;
};

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "FragTrap " << this->_name << " contructor called" << RESET << std::endl;

};

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << GREEN << "FragTrap copy contructor called" << RESET << std::endl;
	*this = copy;

};

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap destructor called" << RESET << std::endl;
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
	std::cout << BLUE << "FragTrap " << this->_name << ": HighFivesGuys!" << RESET << std::endl;
};