/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:00:52 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/09 10:08:02 by madmax42         ###   ########.fr       */
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
	std::cout << "---------------- free space -------------------" << std::endl;
	delete[] zombie;
	return (0);
}