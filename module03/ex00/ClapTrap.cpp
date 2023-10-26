/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:05:36 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/26 11:16:34 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	
	std::cout << GREEN << "ClapTrap default constructor called" << std::endl;
	std::cout << RESET;
};

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << YELLOW << "ClapTrap constructor called" << std::endl;
	std::cout << RESET;
};

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << YELLOW << "ClapTrap copy constructor called" << std::endl;
	std::cout << RESET;
	*this = copy;
};

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap destructor called" << std::endl;
	std::cout << RESET;
};

// getter
std::string	ClapTrap::getName(void) const
{
	return (this->_name);
};

int			ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
};

int			ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
};

int			ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
};

// and setter

void		ClapTrap::setName(std::string name)
{
	this->_name = name;
};

void		ClapTrap::setHitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
};

void		ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
};

void		ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
};

// operator overlord

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
};

// methods function

void	ClapTrap::attack(std::string const &target)
{
	if (!_hitPoints) {
		std::cout << ORANGE << "ClapTrap " << this->_name << " can't attack! is already dead!" << std::endl;
		std::cout << RESET;
		return ;
	}
	if (!_energyPoints) {
		std::cout << ORANGE << "ClapTrap " << this->_name << " can't attack! not energy!" << std::endl;
		std::cout << RESET;
		return ;
	}
	std::cout << BLUE << "ClapTrap " << this->_name << " attack " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	std::cout << RESET;
	_energyPoints -= 1;
	return ;
};

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints) {
		std::cout << ORANGE << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		std::cout << RESET;
		return ;
	}
	if (amount >= static_cast<unsigned int>(_hitPoints)) {
		_hitPoints = 0;
		std::cout << ORANGE << "ClapTrap " << this->_name << " take " << amount << " points of damage and die!" << std::endl;
		std::cout << RESET;
	} else {
		_hitPoints -= amount;
		std::cout << ORANGE << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
		std::cout << RESET;
	}
};

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints) {
		std::cout << YELLOW << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		std::cout << RESET;
		return ;
	}
	if (!_energyPoints) {
		std::cout << YELLOW << "ClapTrap " << this->_name << " can't be repaired!" << std::endl;
		std::cout << RESET;
		return ;
	}
	_hitPoints += amount;
	std::cout << YELLOW << "ClapTrap" << this->_name << " be repaired " << amount << " points of damage!" << std::endl;
	std::cout << RESET;
	_energyPoints -= 1;
	return ;
};