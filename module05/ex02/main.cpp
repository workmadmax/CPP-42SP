/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:29:51 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/04 10:42:03 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void)
{
	// test subject class

	try {
		Bureaucrat	bob("Bob", 42);
		Bureaucrat	jim("Jim", 42);
		Bureaucrat	tricia("Tricia", 42);
		ShrubberyCreationForm	shrub("shrub");
		RobotomyRequestForm		robot("Bender");
		PresidentialPardonForm	pres("Zaphod");
		std::cout << bob << std::endl;
		std::cout << jim << std::endl;
		std::cout << shrub << std::endl;

		bob.executeForm(shrub);
		bob.signForm(shrub);
		jim.executeForm(robot);
		jim.signForm(robot);
		tricia.executeForm(pres);
		tricia.signForm(pres);
	
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}