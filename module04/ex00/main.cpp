/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:43:10 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/28 16:08:39 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main (void)
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const Animal* wrongI = new WrongAnimal();
	const Animal* wrongJ = new WrongCat();

	
	std::cout << "===========================================" << std::endl;
	std::cout << "============= test reference ==============" << std::endl;

	std::cout << "meta->getType(): " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << "i->getType(): " << i->getType() << std::endl;
	i->makeSound();
	std::cout << "j->getType(): " << j->getType() << std::endl;
	j->makeSound();
	
	std::cout << "===========================================" << std::endl;
	std::cout << "=========== Wrong class Test ==============" << std::endl;

	std::cout << wrongI->getType() << " " << std::endl;
	wrongI->makeSound();
	
	std::cout << "===========================================" << std::endl;

	std::cout << wrongJ->getType() << " " << std::endl;
	wrongJ->makeSound();
	
	std::cout << "===========================================" << std::endl;
	std::cout << "=============== test instance =============" << std::endl;
	
	const Animal		instanceMeta;
	const Dog			instanceDog;
	const Cat			instanceCat;
	const WrongAnimal	wrongAnimal;
	const WrongCat		wrongCat;

	std::cout << "instanceMeta.getType(): " << instanceMeta.getType() << std::endl;
	std::cout << "instanceDog.getType(): " << instanceDog.getType() << std::endl;
	std::cout << "cat.getType(): " << instanceCat.getType() << std::endl;
	std::cout << "wrongAnimal.getType(): " << wrongAnimal.getType() << std::endl;
	std::cout << "wrongCat.getType(): " << wrongCat.getType() << std::endl;

	std::cout << "===========================================" << std::endl;

	instanceMeta.makeSound();
	instanceDog.makeSound();
	instanceCat.makeSound();
	wrongAnimal.makeSound();
	wrongCat.makeSound();

	std::cout << "============================================" << std::endl;

	std::cout << "============================================" << std::endl;
	std::cout << "================= test copy ================" << std::endl;
	
	const Animal		copyMeta(instanceMeta);
	const Dog			copyDog(instanceDog);
	const Cat			copyCat(instanceCat);
	const WrongAnimal	copyWrongAnimal(wrongAnimal);
	const WrongCat		copyWrongCat(wrongCat);

	std::cout << "============================================" << std::endl;
	std::cout << "copyMeta.getType(): " << copyMeta.getType() << std::endl;
	std::cout << "copyDog.getType(): " << copyDog.getType() << std::endl;
	std::cout << "copyCat.getType(): " << copyCat.getType() << std::endl;
	std::cout << "copyWrongAnimal.getType(): " << copyWrongAnimal.getType() << std::endl;
	std::cout << "copyWrongCat.getType(): " << copyWrongCat.getType() << std::endl;

	std::cout << "============================================" << std::endl;
	
	copyMeta.makeSound();
	copyDog.makeSound();
	copyCat.makeSound();
	copyWrongAnimal.makeSound();
	copyWrongCat.makeSound();
	
	// free memory with delete 
	
	delete meta;
	delete i;
	delete j;
	delete wrongI;
	delete wrongJ;
	
	return (0);
}

