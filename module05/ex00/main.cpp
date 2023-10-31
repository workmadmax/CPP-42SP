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
	std::cout << "entrou aqui " << std::endl;
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

int main (void)
{
	
	try {
		Bureaucrat bureaucrat("mdouglas", 50);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		testIncrementGrade(bureaucrat);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("MAX", 20);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		testDecrementGrade(bureaucrat);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}