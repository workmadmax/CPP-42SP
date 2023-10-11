/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:11:18 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/11 14:38:58 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <map>

// color

const std::string	RED("\033[0;31m");
const std::string	GREEN("\033[0;32m");
const std::string	YELLOW("\033[0;33m");
const std::string	BLUE("\033[0;34m");

class Harl
{
private:
	void		_debug();
	void		_info();
	void		_warning();
	void		_error();

public:

	Harl();
	~Harl();
	
	void complain(std::string level);
};