/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:44:33 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/27 10:10:28 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

static void print_status(ClapTrap &claptrap)
{
	std::cout << "Name: " << claptrap.getName() << std::endl;
	std::cout << "Hit points: " << claptrap.getHitPoints() << std::endl;
	std::cout << "Energy points: " << claptrap.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << claptrap.getAttackDamage() << std::endl;
	std::cout << std::endl;
};

int main (void)
{
	FragTrap fragTrap; // default constructor
	FragTrap fragTrap2("Bender"); // name constructor

	// operator overlord
	fragTrap = fragTrap2;
	print_status(fragTrap);

	// test methods functions highFivesGuys
	fragTrap.highFivesGuys();
	fragTrap2.highFivesGuys();

	// test methods functions attack
	fragTrap.attack("Bender");
	fragTrap2.takeDamage(20);
	fragTrap2.beRepaired(10);

	// polimorfism

	ClapTrap *clapTrap = new FragTrap("Clappy");
	print_status(*clapTrap);
	clapTrap->attack("Bender");
	delete clapTrap;

	return (0);
}