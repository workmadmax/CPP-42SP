/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:51:47 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/21 11:56:12 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <map>
#include "easyfind.hpp"

void testListContainer(void)
{
	std::list<int> test;
	test.push_back(155);
	test.push_back(156);
	test.push_back(157);

	std::list<int>::const_iterator it;
	try {
		it = easyfind(test, 155);
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		it = easyfind(test, 15);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	testVectorContainer(void)
{
	std::vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);

	std::vector<int>::const_iterator it;
	try {
		it = easyfind(test, 2);
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		it = easyfind(test, 15);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	testFindChar( void )
{
	std::vector<char>	test;
	test.push_back('a');
	test.push_back('b');
	test.push_back('c');
	
	std::vector<char>::const_iterator it;
	try {
		it = easyfind(test, 'b');
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		it = easyfind(test, 'z');
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "------- List --------" << std::endl;
	testListContainer();
	std::cout << "------- Vector ------" << std::endl;
	testVectorContainer();
	std::cout << "------- Char --------" << std::endl;
	testFindChar();
	std::cout << "---------------------" << std::endl;
	return (0);
}

/*
std::vector<char> v;
	v.push_back('1');
	v.push_back('2');
	v.push_back('3');
	print(v);
	try
	{
		std::cout << *easyfind(v, 2) << std::endl;
		std::cout << *easyfind(v, 3) << std::endl;
		std::cout << *easyfind(v, 4) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);*/