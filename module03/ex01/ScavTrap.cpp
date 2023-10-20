/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:04:26 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/20 16:21:38 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor passing the name: " << _name << "as parameter called" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
};

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << "destructed called" << std::endl;
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
	std::cout << "ScavTrap " << _name << " attack " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
};

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " has enterred in Gate keeper mode" << std::endl;
};
