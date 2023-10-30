/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:21:20 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/29 19:34:53 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *_brain;

public:
	Cat(void);
	Cat(const Cat &copy);
	virtual ~Cat();

	Cat	&operator=(const Cat &copy);

	void	makeSound(void) const;
};