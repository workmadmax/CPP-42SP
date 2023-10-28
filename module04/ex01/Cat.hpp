/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:36:17 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 16:36:58 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain*	_brain;

public:
	Cat(void);
	Cat(const Cat &copy);
	virtual ~Cat();

	Cat &operator=(const Cat &copy);

	void makeSound(void) const;
};