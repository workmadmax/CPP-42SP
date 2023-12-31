/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:15:43 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/23 19:19:44 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

void	testSingleSetPDF ( void )
{
	std::cout << "Test single set" << std::endl;
	Span sp = Span(5);
	try {
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};


void	testErrorOverSizeTest ( void )
{
	std::cout << "Test over size" << std::endl;
	Span sp = Span(5);
	try {
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(100, 10000);
		sp.addNumber(1);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

void	testErrorEmpty ( void )
{
	std::cout << "Test empty" << std::endl;
	Span sp = Span(5);
	try {
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

void	testMultiSet ( void )
{
	std::cout << "Test multi set" << std::endl;
	Span sp = Span(333);
	try {
		sp.addNumber(3);
		sp.addNumber(18);
		sp.addNumber(21);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

void	 testSpan( void )
{
	std::cout << "Test span" << std::endl;
	Span sp = Span(5);
	try {
		sp.addNumber(3);
		sp.addNumber(18);
		sp.addNumber(21);
		sp.addNumber(1);
		sp.addNumber(100);
		sp.addNumber(1);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};


int	 main(  )
{
	testSpan();
	return (0);
}