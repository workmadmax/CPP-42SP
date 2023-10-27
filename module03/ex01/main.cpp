/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:54:54 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/27 08:31:40 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void print_status(ClapTrap &claptrap)
{
    if (claptrap.getName() == "palmeiras")
    {
        std::cout << GREEN;
        std::cout << "Name: " << claptrap.getName() << std::endl;
        std::cout << "Hit points: " << claptrap.getHitPoints() << std::endl;
        std::cout << "Energy points: " << claptrap.getEnergyPoints() << std::endl;
        std::cout << "Attack damage: " << claptrap.getAttackDamage() << std::endl;
        std::cout << std::endl;
        std::cout << RESET;
    }
    else if (claptrap.getName() == "cortinas")
    {
        std::cout << YELLOW;
        std::cout << "Name: " << claptrap.getName() << std::endl;
        std::cout << "Hit points: " << claptrap.getHitPoints() << std::endl;
        std::cout << "Energy points: " << claptrap.getEnergyPoints() << std::endl;
        std::cout << "Attack damage: " << claptrap.getAttackDamage() << std::endl;
        std::cout << std::endl;
        std::cout << RESET;
    }
    else
    {
        std::cout << "Name: " << claptrap.getName() << std::endl;
        std::cout << "Hit points: " << claptrap.getHitPoints() << std::endl;
        std::cout << "Energy points: " << claptrap.getEnergyPoints() << std::endl;
        std::cout << "Attack damage: " << claptrap.getAttackDamage() << std::endl;
        std::cout << std::endl;
    }
};

static void		battle(ScavTrap &scavTrap, ClapTrap &clapTrap)
{
	scavTrap.setAttackDamage(1);
	while (scavTrap.getEnergyPoints() > 0 && clapTrap.getHitPoints() > 0)
	{
		scavTrap.attack(scavTrap.getName());
		clapTrap.takeDamage(scavTrap.getAttackDamage());
	}
	std::cout << GRAY << "------ status after battle ------" << RESET << std::endl;
	print_status(clapTrap);
	print_status(scavTrap);
};

int	main (void)
{
	ScavTrap	trikas;
	ScavTrap	palmeiras("palmeiras");
	ClapTrap	cortinas("cortinas");

	std::cout << GRAY << "=========== trikas ==========" << RESET << std::endl;
	trikas.setName("trikas");
	trikas.setAttackDamage(2);
	trikas.setEnergyPoints(7);
	trikas.setHitPoints(3);
	print_status(trikas);

	std::cout << GRAY << "=========== status ==========" << RESET << std::endl;
	print_status(palmeiras);
	std::cout << std::endl;
	print_status(cortinas);
	std::cout << std::endl;

	// test battle
	std::cout << GRAY << "=========== mini battle ==========" << RESET << std::endl;
	battle(palmeiras, cortinas);

    std::cout << GRAY << "=========== test heritage ==========" << RESET << std::endl;
    palmeiras.setAttackDamage(2);
    palmeiras.setEnergyPoints(7);
    palmeiras.setHitPoints(3);
    palmeiras.setName("PALMEIRAS");
    print_status(palmeiras);

};