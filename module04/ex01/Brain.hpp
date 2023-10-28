/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:24:17 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 16:25:46 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];

public:
	Brain(void);
	Brain(const Brain &copy);
	~Brain();

	Brain &operator=(const Brain &copy);
};