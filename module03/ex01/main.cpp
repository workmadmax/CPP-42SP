/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:54:54 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/20 16:33:14 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void		print_status(ClapTrap &claptrap)
{
	if (claptrap.getName() == "palmeiras")
	{
		std::cout << green;
		std::cout << "Name: " << claptrap.getName() << std::endl;
		std::cout << "Hit points: " << claptrap.getHitPoints() << std::endl;
		std::cout << "Energy points: " << claptrap.getEnergyPoints() << std::endl;
		std::cout << "Attack damage: " << claptrap.getAttackDamage() << std::endl;
		std::cout << std::endl;
		std::cout << reset;
	}
	if (claptrap.getName() == "cortinas")
	{
		std::cout << yellow;
		std::cout << "Name: " << claptrap.getName() << std::endl;
		std::cout << "Hit points: " << claptrap.getHitPoints() << std::endl;
		std::cout << "Energy points: " << claptrap.getEnergyPoints() << std::endl;
		std::cout << "Attack damage: " << claptrap.getAttackDamage() << std::endl;
		std::cout << std::endl;
		std::cout << reset;
	}
};

static void		battle(ScavTrap &scavTrap, ClapTrap &clapTrap)
{
	clapTrap.setAttackDamage(1);
	while (clapTrap.getEnergyPoints() > 0 && scavTrap.getHitPoints() > 0)
	{
		clapTrap.attack(scavTrap.getName());
		scavTrap.takeDamage(clapTrap.getAttackDamage());
	}
	std::cout << green;
	print_status(clapTrap);
	std::cout << yellow;
	print_status(scavTrap);
	std::cout << reset;
};

// test be reapaired

int	main (void)
{
	ScavTrap	cortinas("cortinas");
	ClapTrap	palmeiras("palmeiras");

	print_status(palmeiras);
	std::cout << std::endl;
	print_status(cortinas);
	std::cout << std::endl;

	battle(cortinas, palmeiras);

};