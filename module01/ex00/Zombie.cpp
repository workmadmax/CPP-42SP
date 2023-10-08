/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:10:14 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/01 11:14:41 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
};

Zombie::Zombie() {
	std::cout << "Zombie created" << std::endl;
	_name = "default";
};

Zombie::Zombie(std::string name) {
	std::cout << "Zombie created" << std::endl;
	_name = name;
};

Zombie::~Zombie() {
	std::cout << "Zombie destroyed" << std::endl;
};

void Zombie::announce() const {
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
};
