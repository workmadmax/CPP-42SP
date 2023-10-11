/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:16:44 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/11 14:40:12 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::_debug() {
	std::cout << BLUE
	<< "I love having extra bacon for my XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< std::endl;
}

void	Harl::_info() {
	std::cout << GREEN
	<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
	<< std::endl;
}

void	Harl::_warning() {
	std::cout << RED
	<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
	<< std::endl;
}

void	Harl::_error() {
	std::cout << YELLOW
	<< "This is unacceptable, I want to speak to the manager now."
	<< std::endl;
}

void	Harl::complain(std::string level) {
	std::map<std::string, std::function<void()>> complainMap;

	complainMap["DEBUG"] = std::bind(&Harl::_debug, this);
	complainMap["INFO"] = std::bind(&Harl::_info, this);
	complainMap["WARNING"] = std::bind(&Harl::_warning, this);
	complainMap["ERROR"] = std::bind(&Harl::_error, this);

	complainMap[level]();
}