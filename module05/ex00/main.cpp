/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:52:01 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/08 15:17:24 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void testIncrementGrade(void)
{
	try {
		Bureaucrat testIncrement("marvin", 150);
		std::cout << "test name: " << testIncrement.getName() << std::endl;
		std::cout << "test grade: " << testIncrement.getGrade() << std::endl;
		while (true) {
			std::cout << "Grade is " << testIncrement.getGrade() << std::endl;
			if(testIncrement.getGrade() == 1)
				std::cout << " (max)" << std::endl;
			else
				std::cout << std::endl;
			testIncrement.incrementGrade();
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

void	testDecrementGrade( void )
{
	try {
		Bureaucrat testDecrement("marvin", 1);
		std::cout << "test name: " << testDecrement.getName() << std::endl;
		std::cout << "test grade: " << testDecrement.getGrade() << std::endl;
		while (true) {
			std::cout << "Grade is " << testDecrement.getGrade() << std::endl;
			if(testDecrement.getGrade() == 150)
				std::cout << " (min)" << std::endl;
			else
				std::cout << std::endl;
			testDecrement.decrementGrade();
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

void	testAssignationOperator( void )
{
	try {
		Bureaucrat copy;
		Bureaucrat test("marvin", 1);
		copy = test;
		std::cout << "Copy name: " << copy.getName() << std::endl;
		std::cout << "Copy grade: " << copy.getGrade() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

void	testCreateException( void )
{
	try {
		Bureaucrat test("marvin", 0);
		std::cout << "test name: " << test.getName() << std::endl;
		std::cout << "test grade: " << test.getGrade() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat test("marvin", 151);
		std::cout << "test name: " << test.getName() << std::endl;
		std::cout << "test grade: " << test.getGrade() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

void testOperatorOverload( void )
{
	try {
		Bureaucrat test("marvin", 1);
		std::cout << test;
		test.incrementGrade();
		std::cout << test;
		test.decrementGrade();
		std::cout << test;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

int main (void)
{
	std::cout << GREY << "================================" << std::endl;
	std::cout << GREY << "test increment grade: ==========" << std::endl;
	//testIncrementGrade();
	
	std::cout << GREY << "================================" << std::endl;
	std::cout << GREY << "test decrement grade: ==========" << std::endl;
	//testDecrementGrade();


	std::cout << GREY << "================================" << std::endl;
	std::cout << GREY << "test assignation operator: " << std::endl;
	//testAssignationOperator();

	std::cout << GREY << "================================" << std::endl;
	std::cout << GREY << "test create exception: " << RESET << std::endl;
	testCreateException();

	/* std::cout << GREY << "================================" << std::endl;
	std::cout << GREY << "test operator overload: " << RESET << std::endl;
	testOperatorOverload(); */

	return (0);
};