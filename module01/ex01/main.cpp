/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:00:52 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/08 15:27:17 by madmax42         ###   ########.fr       */
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
	zombie = zombieHorde(5, "Max");
	delete[] zombie;
	return (0);
}