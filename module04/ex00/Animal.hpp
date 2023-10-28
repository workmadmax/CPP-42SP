/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:43:26 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 10:07:35 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define RESET "\033[0m"
# define ORANGE "\033[38;5;208m"
# define GRAY "\033[38;5;246m"

/// @brief the Animal class which is the base class for Cat and Dog
/// @param _type the type of the animal (Animal, Cat or Dog)
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