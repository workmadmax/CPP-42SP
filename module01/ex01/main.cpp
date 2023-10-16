/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:00:52 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/11 15:45:50 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	Zombie *zombie = newZombie("Max");
	zombie->announce();
	delete zombie;
	randomChump("Bob");
	std::cout << "------------------ horde zombie -------------------" << std::endl;
	zombie = zombieHorde(5, "");
	zombie[0].announce();
	zombie[1].announce();
	zombie[2].announce();
	zombie[3].announce();
	zombie[4].announce();
	std::cout << "---------------- free space -------------------" << std::endl;
	delete[] zombie;
	return (0);
}