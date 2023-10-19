/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:05:50 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/19 13:31:34 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string _name;
	int         _hitPoints;
	int         _energyPoints;
	int         _attackDamage;

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