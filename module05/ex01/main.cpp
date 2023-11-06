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

void testToSignedForm(void)
{
	try {
		Bureaucrat *test1 = new Bureaucrat("max", 150);
		Bureaucrat *test2 = new Bureaucrat("leila", 20);
		Bureaucrat *test3 = new Bureaucrat("mohamed", 31);
		Form		*ecole = new Form("ecole", 30, 20);

		std::cout << GREY << "=========================" << std::endl;
		std::cout << "test one: " << RESET << std::endl;
		try {
			test1->signForm(*ecole);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << GREY << "=========================" << std::endl;
		std::cout << "test two: " << RESET << std::endl;
		try {
			test2->signForm(*ecole);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << GREY << "=========================" << std::endl;
		std::cout << "test three: " << RESET << std::endl;
		try {
			test3->signForm(*ecole);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		delete test1;
		delete test2;
		delete test3;
		delete ecole;
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

void	testAssignationOperator(void)
{
	try {
		Bureaucrat *test1;
		Bureaucrat *test2 = new Bureaucrat("leila", 20);
		Bureaucrat *test3 = new Bureaucrat("mohamed", 31);

		std::cout << GREY << "=========================" << std::endl;
		std::cout << "test one: " << RESET << std::endl;
		test1 = test2;
		std::cout << "test1: " << test1->getName()
		<< " grade : "	<< test1->getGrade() << std::endl;
		Form *ecole = new Form("ecole", 30, 20);
		test1->signForm(*ecole);

		delete test2;
		delete test3;
		delete ecole;
		
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

int main (void)
{
	testToSignedForm();
	testAssignationOperator();
	return (0);
};