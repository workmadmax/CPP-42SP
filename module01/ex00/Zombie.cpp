/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:10:14 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/09 10:13:40 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor default
Zombie::Zombie() {
	std::cout << GREEN << "Zombie created" << std::endl;
};

// Constructor with name
Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << YELLOW << "Zombie created" << std::endl;
};

// Destructor
Zombie::~Zombie() {
	std::cout << RED << "Zombie destroyed" << std::endl;
	std::cout << RESET;
};

//getters
std::string Zombie::getName(void) {
	return (this->_name);
};

// setters
std::string Zombie::setName(std::string name) {
	this->_name = name;
	return (this->_name);
};

// methods functions
void	Zombie::announce(void) {
	std::cout << BLUE << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
