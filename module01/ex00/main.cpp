/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:02:31 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/08 12:34:44 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void) {
	
	std::cout << "Test zombie class using Heap Allocation :" << std::endl;
	Zombie *zombie1 = new Zombie("zombie1");
	zombie1->announce();
	delete zombie1;

	std::cout << "Test zombie class using Heap Allocation constructor default :" << std::endl;
	Zombie *zombie2 = new Zombie();
	zombie2->setName("zombie2");
	delete zombie2;

	std::cout << "Test zombie class using Stack Allocation :" << std::endl;
	randomChump("zombie3");
	return (0);	
}