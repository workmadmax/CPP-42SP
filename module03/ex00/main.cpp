/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:05:26 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/19 13:21:35 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap	palmeiras("Palmeiras");
	ClapTrap	corinthians("Corinthians");

	palmeiras.attack("Corinthians");
	corinthians.takeDamage(5);
	corinthians.beRepaired(3);
	
	corinthians.attack("Palmeiras");
	palmeiras.takeDamage(5);
	palmeiras.beRepaired(3);

	return (0);
}