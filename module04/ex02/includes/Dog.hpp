/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:22:01 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/29 19:34:56 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain *_brain;

public:
	Dog(void);
	Dog(const Dog &copy);
	virtual ~Dog();

	Dog	&operator=(const Dog &copy);

	void	makeSound(void) const;	
};