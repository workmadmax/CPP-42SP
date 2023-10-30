/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:19:22 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/29 19:34:49 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AAnimal.hpp"

class Brain
{
private:
	std::string	_ideas[100];

public:
	Brain(void);
	Brain(const Brain &copy);
	virtual ~Brain();
	
	Brain	&operator=(const Brain &copy);
};