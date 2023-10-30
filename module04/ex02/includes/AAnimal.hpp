/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:14:15 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/29 19:29:22 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define GRAY "\033[37m"
# define ORANGE "\033[38;5;208m"
# define PINK "\033[38;5;219m"
# define RESET "\033[0m"


class AAnimal
{
protected:
	std::string	_type;

public:
	AAnimal(void);
	AAnimal(const AAnimal &copy);
	AAnimal(std::string const &type);
	virtual ~AAnimal();
	
	AAnimal	&operator=(const AAnimal &copy);

	std::string			getType(void) const;
	virtual void		makeSound(void) const = 0;
};