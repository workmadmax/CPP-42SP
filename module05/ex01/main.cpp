/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:11:14 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/01 15:15:45 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main (void)
{
	try {
		Bureaucrat *test1 = new Bureaucrat("max", 150);
		Bureaucrat *test2 = new Bureaucrat("leila", 20);
		Form		*ecole = new Form("ecole", 30, 20);

		std::cout << std::endl << *ecole << std::endl;
		try {
			test1->signForm(*ecole);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl << *ecole << std::endl;
		try {
			test2->signForm(*ecole);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		delete test1;
		delete test2;
		delete ecole;
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}