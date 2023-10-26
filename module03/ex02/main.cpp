/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:44:33 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/26 15:20:55 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	FragTrap fragTrap; // default constructor
	FragTrap fragTrap2("Bender"); // name constructor

	// test methods functions highFivesGuys
	fragTrap.highFivesGuys();
	fragTrap2.highFivesGuys();

	// test methods functions attack
	fragTrap.attack("Bender");
	fragTrap2.takeDamage(20);
	fragTrap2.beRepaired(10);

	// polimorfism

	ClapTrap *clapTrap = new FragTrap("Clappy");
	clapTrap->attack("Bender");
	delete clapTrap;

	return (0);
}