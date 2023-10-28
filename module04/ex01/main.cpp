/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:38:50 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 16:43:41 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "stdlib.h"


int	main (void)
{
	Animal*	animals[100];
	for (int i = 0; i < 100; i++) {
		if (i < 50) animals[i] = new Dog();
		else animals[i] = new Cat();
	}
	for (int i = 0; i < 100; i++) {
		delete animals[i];
	}
	system("leaks a.out");
	return (0);
}