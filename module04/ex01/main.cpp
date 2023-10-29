/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:38:50 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 19:32:46 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "stdlib.h"

static void testArrayAnimal(Animal **animals)
{
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
};

static void testCopyAnimal(Animal *animal)
{
	if (Dog *dog = dynamic_cast<Dog*>(animal)) {
		Dog *copy_dog = new Dog(*dog);
		std::cout << "copy_dog type: "	<< copy_dog->getType() << std::endl;
		delete copy_dog;
	}
	else if (Cat *cat = dynamic_cast<Cat*>(animal)) {
		Cat *copy_cat = new Cat(*cat);
		std::cout << "copy_cat type: "	<< copy_cat->getType() << std::endl;
		delete copy_cat;
	}
};

int	main (void)
{
	Animal*	animals[10];
	int		index;
	
	testArrayAnimal(animals);
	std::cout << GRAY << "====================================" << RESET << std::endl;
	std::cout << GRAY << "========= init test copy : =========" << RESET << std::endl;
	index = 0;
	while (index < 10 && animals[index] != NULL) {
		testCopyAnimal(animals[index]);
		index++;
	}
	// delete animals
	index = 0;
	while (index < 10 && animals[index] != NULL) {
		delete animals[index];
		index++;
	}
	return (0);
}