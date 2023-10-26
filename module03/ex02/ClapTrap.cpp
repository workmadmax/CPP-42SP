/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:55:22 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/26 10:28:53 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default contructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name contructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy contructor called" << std::endl;
	*this = copy;
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
};

// getters

std::string	ClapTrap::getName() const
{
	return (this->_name);
};

int			ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
};

int			ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
};

int			ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
};

// setters

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

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &c)
	{
		this->_name = c._name;
		this->_hitPoints = c._hitPoints;
		this->_energyPoints = c._energyPoints;
		this->_attackDamage = c._attackDamage;
	}
	return (*this);
};

// methods function

void		ClapTrap::attack(std::string const &target)
{
	if (!_hitPoints) {
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		return ;
	}
	if (!_energyPoints) {
		std::cout << "ClapTrap " << this->_energyPoints << " can't attack!" << std::endl;
	}
	std::cout << "ClapTrap " << this->_name << " attack " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
};

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints) {
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		return ;
	}
	if (amount > static_cast<unsigned int>(_hitPoints)) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << "take" << amount << " is dead!" << std::endl;
	}
		
	else {
		_hitPoints -= amount;
		std::cout << "ClapTrap" << this->_name << " take " << amount << " points of damage!" << std::endl;
	}
};

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints) {
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		return ;
	}
	if (!_energyPoints) {
		std::cout << "ClapTrap " << this->_energyPoints << " can't be repaired!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " be repaired " << amount << " points of damage!" << std::endl;
	_energyPoints -= 1;
	return ;
};
