/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:20:32 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/11 15:45:58 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief An array of names to choose from when generating a random name.
 * 
 */
const	std::string NAMES[] = {
	"Max",
	"Bob",
	"John",
	"Jack",
	"Richard",
	"Alex",
	"Rick",
	"Michonne",
	"Carl"
};

/**
 * @brief Generates a random name based on the given name.
 * 
 * @param name The base name to generate a random name from.
 * @return std::string A randomly generated name.
 */
std::string getRandomName(std::string name)
{
	int	randomIndex;
	std::string randomName;
	do {
		randomIndex = std::rand() % (sizeof(NAMES) / sizeof(NAMES[0]));
		randomName = NAMES[randomIndex];
	} while (randomName == name);
	return (randomName);
};

/**
 * @brief Allocates an array of N zombies and returns a pointer to the first zombie.
 * 
 * @param N The number of zombies to allocate.
 * @param name The name to give to all zombies in the horde.
 * @return Zombie* A pointer to the first zombie in the horde.
 */
Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		
		zombies[i].setName(getRandomName(name));
		//zombies[i].announce();
	}
	std::cout << GREEN << "Zombie horde created" << RESET << std::endl;
	return (zombies);
};