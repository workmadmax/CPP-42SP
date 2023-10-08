/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:02:31 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/08 12:05:57 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void) {
	
	Zombie *zombie1 = new Zombie("zombie1");
	zombie1->announce();
	delete zombie1;

	Zombie *zombie2 = new Zombie();
	zombie2->setName("zombie2");

	randomChump("zombie3");
	return (0);	
}