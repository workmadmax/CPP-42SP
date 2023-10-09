/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:13:06 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/09 10:13:49 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creates a new instance of Zombie with the given name and calls its announce method.
 * 
 * @param name The name of the Zombie to be created.
 */
void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.announce();
}