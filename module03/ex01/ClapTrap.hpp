/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:27:50 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/20 16:15:59 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

const std::string	red("\033[0;31m");
const std::string	green("\033[0;32m");
const std::string	yellow("\033[0;33m");
const std::string	blue("\033[0;34m");
const std::string	orange("\033[0;38;5;208m");
const std::string 	reset("\033[0m");

class ClapTrap
{
protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	
public:
	//constructor & destructor
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	~ClapTrap();

	//operator overlord
	ClapTrap	&operator=(const ClapTrap &copy);

	// getter and setter

	std::string	getName(void) const;
	int			getHitPoints(void) const;
	int			getEnergyPoints(void) const;
	int			getAttackDamage(void) const;

	void		setName(std::string name);
	void		setHitPoints(int hitPoints);
	void		setEnergyPoints(int energyPoints);
	void		setAttackDamage(int attackDamage);

	// methods function

	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);	
};