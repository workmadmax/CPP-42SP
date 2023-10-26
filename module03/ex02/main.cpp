/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:44:33 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/26 10:46:39 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	FragTrap	robot("R2D2");

	robot.attack("C3PO");
	robot.takeDamage(5);
	robot.beRepaired(10);
	robot.highFivesGuys();

	// test constructor calls
	std::cout << "-------- Constructor calls --------" << std::endl;
	FragTrap	robot2;
	return (0);
}