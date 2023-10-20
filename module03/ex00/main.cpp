/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:05:26 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/20 11:22:24 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void		print_status(ClapTrap &claptrap)
{
	std::cout << "Name: " << claptrap.getName() << std::endl;
	std::cout << "Hit points: " << claptrap.getHitPoints() << std::endl;
	std::cout << "Energy points: " << claptrap.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << claptrap.getAttackDamage() << std::endl;
	std::cout << std::endl;
};

int main (void)
{
	ClapTrap	palmeiras("Palmeiras");
	ClapTrap	cortinas("Cortinas");


	while (true)
	{
		palmeiras.attack("Cortinas");
		palmeiras.setAttackDamage(palmeiras.getAttackDamage() + 1);
		cortinas.takeDamage(palmeiras.getAttackDamage());
		if (palmeiras.getEnergyPoints() == 0)
		{
			print_status(palmeiras);
			print_status(cortinas);
			break ;
		}
	}
	
	palmeiras.setEnergyPoints(0);
	palmeiras.attack("Cortinas");

	palmeiras.setEnergyPoints(10);
	palmeiras.attack("Cortinas");
	palmeiras.setHitPoints(0);
	palmeiras.attack("Cortinas");
	
	print_status(cortinas);
	cortinas.beRepaired(10);
	palmeiras.setHitPoints(2);
	cortinas.setHitPoints(10);
	cortinas.setAttackDamage(1);
	cortinas.attack("Palmeiras");
	palmeiras.takeDamage(cortinas.getAttackDamage());
	print_status(palmeiras);
	print_status(cortinas);
	return (0);
};