/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:47:19 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/09 10:21:31 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << GREEN << "Zombie created" << RESET << std::endl;
};

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << GREEN << "Zombie created" << RESET << std::endl;
};

Zombie::~Zombie()
{
	std::cout << RED << "Zombie destroyed" << RESET << std::endl;
};

std::string	Zombie::getName(void)
{
	return (this->_name);
};

std::string Zombie::setName(std::string name)
{
	this->_name = name;
	return (this->_name);
};

void	Zombie::announce(void)
{
	std::cout << YELLOW << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
};

/**
 * @brief Allocates memory for a new Zombie object and initializes it with the given name.
 * 
 * @param name The name of the Zombie.
 * @return Zombie* A pointer to the newly created Zombie object.
 */
Zombie* newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
};

/**
 * @brief Creates a Zombie object with a random type and the given name.
 * 
 * @param name The name of the Zombie object.
 */
void	randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
};
