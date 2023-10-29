/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:15:40 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 16:28:27 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

# define GRAY "\033[90m"
# define RED "\033[91m"
# define GREEN "\033[92m"
# define YELLOW "\033[93m"
# define BLUE "\033[94m"
# define ORANGE "\033[38;5;208m"
# define RESET "\033[0m"
# define PINK "\033[38;5;219m"

class Animal
{
protected:
	std::string _type;

public:
	Animal(void);
	Animal(std::string const &type);
	Animal(const Animal &copy);
	virtual ~Animal();

	Animal &operator=(const Animal &copy);

	std::string getType(void) const;
	virtual void makeSound(void) const;	
};
