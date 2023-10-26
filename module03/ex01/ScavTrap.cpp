/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:04:26 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/26 11:34:31 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << YELLOW << "ScavTrap default constructor called" << RESET << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << YELLOW << "ScavTrap constructor passing the name: " << _name << "as parameter called" << RESET << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << YELLOW << "ScavTrap copy constructor called" << RESET << std::endl;
	*this = copy;
};

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "ScavTrap " << _name << "destructed called" << RESET << std::endl;
};

// overload operator

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	return (*this);
};

// methods function

void	ScavTrap::attack(std::string const &target)
{
	std::cout << ORANGE << "ScavTrap " << _name << " attack " << target
		<< ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
};

void	ScavTrap::guardGate(void)
{
	std::cout << ORANGE << "ScavTrap " << _name << " has enterred in Gate keeper mode" << RESET << std::endl;
};
