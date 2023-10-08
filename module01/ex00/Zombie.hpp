/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:12:29 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/08 12:32:26 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string YELLOW = "\033[1;33m";
const std::string BLUE = "\033[1;34m";
const std::string RESET = "\033[0m";
const std::string MAGENTA = "\033[1;35m";

class Zombie
{
	public:
			Zombie();
			Zombie(std::string name);
			~Zombie();

			std::string getName(void);
			std::string setName(std::string name);

			void	announce(void);
	private:
			std::string _name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif