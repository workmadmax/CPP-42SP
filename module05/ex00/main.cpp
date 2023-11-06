/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:52:01 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/31 16:33:51 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void testIncrementGrade( Bureaucrat &bureaucrat )
{
	try {
		while (bureaucrat.getGrade()) {
			if ( bureaucrat.getGrade() == 150 )
				std::cout << "Grade is " << bureaucrat.getGrade() << " (max)" << std::endl;
			else
				std::cout << "Grade is " << bureaucrat.getGrade() << std::endl;
			bureaucrat.incrementGrade();
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

static void	testDecrementGrade( Bureaucrat &bureaucrat )
{
	try {
		while ( bureaucrat.getGrade()) {
			if (bureaucrat.getGrade() == 1)
				std::cout << "Grade is " << bureaucrat.getGrade() << " (min)" << std::endl;
			else
				std::cout << "Grade is " << bureaucrat.getGrade() << std::endl;
			bureaucrat.decrementGrade();
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

static void	testAssignationOperator( Bureaucrat &bureaucrat )
{
	try {
		Bureaucrat copy;
		copy = bureaucrat;
		std::cout << "Copy name: " << copy.getName() << std::endl;
		std::cout << "Copy grade: " << copy.getGrade() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

static void	testCreateException( void )
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

static void testOperatorOverload( void )
{
	Bureaucrat test("marvin", 1);
	std::cout << test;
	test.incrementGrade();
	std::cout << test;
	test.decrementGrade();
	std::cout << test;
};

int main (void)
{
	std::cout << GREY << "================================" << std::endl;
	std::cout << GREY << "test increment grade: " << std::endl;
	Bureaucrat test("MAX", 1);
	testIncrementGrade(test);
	
	std::cout << GREY << "================================" << std::endl;
	std::cout << GREY << "test decrement grade: " << std::endl;
	Bureaucrat test1("mdouglas", 20);
	testDecrementGrade(test1);

	std::cout << GREY << "================================" << std::endl;
	std::cout << GREY << "test assignation operator: " << std::endl;
	Bureaucrat testCopy;
	testAssignationOperator(testCopy);

	std::cout << GREY << "================================" << std::endl;
	std::cout << GREY << "test create exception: " << RESET << std::endl;
	testCreateException();

	std::cout << GREY << "================================" << std::endl;
	std::cout << GREY << "test operator overload: " << RESET << std::endl;
	testOperatorOverload();

	return (0);
};