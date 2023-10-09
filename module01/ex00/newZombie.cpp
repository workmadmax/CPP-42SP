/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:09:25 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/09 10:12:06 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include "Zombie.hpp"


/**
 * @brief Allocates memory for a new Zombie object and returns a pointer to it.
 * 
 * @param name The name of the Zombie.
 * @return Zombie* A pointer to the newly created Zombie object.
 */
Zombie* newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
};
